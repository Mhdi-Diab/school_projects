import subprocess, os, signal, time, datetime
from Log import Log

class Program:
	STOPPED = 0
	RUNNING = 1
	NOT_STARTED = 2
	STARTING = 3
	FATAL = 4

	status = 2
	numprocs = 1
	umask = 022
	workingdir = None
	autostart = True
	autorestart = 'unexpected'
	exitcodes = 0
	starttime = None
	startretries = 0
	stopsignal = 'KILL'
	stoptime = None
	cmd = False
	stdout = None
	stderr = None
	process = None
	lastStartTime = None
	lastStopTime = None
	nbFatal = 0
	redirect_stderr = False
	stdout = '/tmp/default.stdout'
	stderr = '/tmp/default.stderr'

	def __init__(self, name, config):
		self.name = name
		self.process = None
		self.setAttributesFromConfig(config)

	def setAttributesFromConfig(self, config):
		for key, value in config.items():
			setattr(self, key, value)
		self.env = os.environ
		if 'env' in config:
			for k, v in config['env'].items():
				self.env[k] = str(v)

	def start(self):
		if self.status != self.FATAL:
			try:
				stdoutFile = open(os.devnull, 'wb') if self.stdout == False else self.getFileFd(self.stdout)
				stderrFile = open(os.devnull, 'wb') if self.stderr == False else self.getFileFd(self.stderr)
				if self.redirect_stderr:
					stderrFile = stdoutFile
				os.umask(self.umask)
				self.process = subprocess.Popen(self.cmd, stdin = subprocess.PIPE , stdout = stdoutFile, stderr = stderrFile,
					env = self.env, cwd = self.workingdir, preexec_fn=os.setsid, shell=True)
				if self.starttime is None or self.starttime == 0:
					self.status = self.RUNNING
				else:
					self.status = self.STARTING
				self.lastStartTime = time.time()
			except Exception as e:
				self.nbFatal += 1
				if self.nbFatal > self.startretries:
					self.status = self.FATAL
				else:
					self.start()
			if self.nbFatal > self.startretries:
				self.status = self.FATAL

	def getStopSignal(self):
		if self.stopsignal == 'KILL':
			return signal.SIGKILL
		elif self.stopsignal == 'TERM':
			return signal.SIGTERM
		elif self.stopsignal == 'HUP':
			return signal.SIGHUP
		elif self.stopsignal == 'INT':
			return signal.SIGINT
		elif self.stopsignal == 'QUIT':
			return signal.SIGQUIT
		elif self.stopsignal == 'USR1':
			return signal.SIGUSR1
		elif self.stopsignal == 'USR2':
			return signal.SIGUSR2
		else:
			return signal.SIGKILL

	def stop(self):
		if (self.status == self.RUNNING):
			try:
				os.killpg(self.process.pid, self.getStopSignal())
				Log.logToFile("Stop " + self.name, Log.INFO)
			except:
				pass

	def forceStop(self):
		try:
			os.killpg(self.process.pid, signal.SIGKILL)
			Log.logToFile("Force Stop " + self.name, Log.WARN)
			self.lastStopTime = None
		except:
			pass

	def restart(self):
		self.stop()
		self.start()

	def reload(self, config):
		restart = False;
		for key, value in config.items():
			if ((key == 'cmd' and value != self.cmd)
				or (key == 'autostart' and value == True and self.autostart == False)):
				restart = True
		self.setAttributesFromConfig(config)
		if (restart):
			self.restart()

	def getPid(self):
		if not self.process:
			return -1
		return self.process.pid

	def autorestartProgram(self):
		if self.autorestart is True:
			self.start()
			Log.logToFile("Autorestarting " + self.name, Log.WARN)
		elif self.autorestart == 'unexpected':
			if (type(self.exitcodes) == list and self.process.returncode in self.exitcodes) or (type(self.exitcodes) == int and self.process.returncode == self.exitcodes):
				self.status = self.STOPPED
			else:
				Log.logToFile("Autorestarting " + self.name, Log.WARN)
				self.start()

	def updateStatus(self):
		if not self.process:
			self.status = self.NOT_STARTED
		elif (self.process.poll() != None):
			if self.status == self.RUNNING and (self.autorestart is True or self.autorestart == 'unexpected'):
				self.autorestartProgram()
			elif self.status == self.STARTING:
				self.nbFatal += 1
				self.start()
			elif self.status != self.FATAL:
				self.status = self.STOPPED
		elif (self.process.poll() == None):
			if self.stoptime and self.lastStopTime and time.time() - self.lastStopTime > self.stoptime:
				self.forceStop()
			elif self.status == self.STARTING:
				if self.starttime is None:
					self.status = self.RUNNING
					Log.logToFile(self.name + " has new state : RUNNING", Log.INFO)
				elif time.time() - self.lastStartTime > self.starttime:
					self.status = self.RUNNING

	def printStatus(self):
		status = ["STOPPED", "RUNNING", "NOT_STARTED", "STARTING", "FATAL"]
		print "Id: %s | Status: %s | PID: %d" % (self.name, status[self.status], self.getPid())

	def printDetailedStatus(self):
		status = ["STOPPED", "RUNNING", "NOT_STARTED", "STARTING", "FATAL"]
		startime = datetime.datetime.fromtimestamp(int(self.lastStartTime)).strftime("%H:%M:%S") if self.lastStartTime else 'None'
		print "Id: %s | Start time: %s | Retries before start: %d | Status: %s | PID: %d" % (self.name, startime, self.nbFatal, status[self.status], self.getPid())

	def getFileFd(self, file):
		if file == None:
			return None
		try:
			fd = open(file, "a")
			return fd
		except Exception as e:
			print(e)
			return None
