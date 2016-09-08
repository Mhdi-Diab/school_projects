import cmd, threading, sys, signal
from select import select
from Log import Log
from Program import Program
from Config import Config

class Commander(cmd.Cmd):
	"""Simple command processor example."""

	_taskmaster = None

	def setTaskmaster(self, taskmaster):
		self._taskmaster = taskmaster

	def sighup_handler(self, signal, frame):
		self._taskmaster.reloadPrograms()

	def preloop(self):
		signal.signal(signal.SIGHUP, self.sighup_handler)
		updates_thread = threading.Thread(target=self.updates_loop)
		updates_thread.daemon = True
		updates_thread.start()

	def updates_loop(self):
		while True:
			self._taskmaster.updateAll()

	def do_status(self, line):
		"""status [program|'all']
		Give the status of a program or all program"""
		if (self._taskmaster.detailedStatus is False):
			self._taskmaster.printProgramsStatus()
		else:
			self._taskmaster.printProgramsDetailedStatus()

	def do_dstatus(self, line):
		self._taskmaster.detailedStatus = False if self._taskmaster.detailedStatus is True else True
		Config.modifyConfig("detailedStatus", self._taskmaster.detailedStatus)

	def do_start(self, line):
		"""start [program|'all']
		Start a program or all program"""
		if line == "":
			print ("Please specify a program name to start")
		elif line == "all":
			self._taskmaster.startAllPrograms()
		else:
			self._taskmaster.startProgram(line)

	def do_stop(self, line):
		"""stop [program|'all']
		Stop a program or all program"""
		if line == "":
			print ("Please specify a program name to stop or all")
		elif line == "all":
			self._taskmaster.stopAllPrograms()
		else:
			self._taskmaster.stopProgram(line)

	def do_restart(self, line):
		"""restart [program|'all']
		Restart a program or all program"""
		print ("restart")

	def do_reload(self, line):
		"""restart [file_path]
		Reload program configuration with path if specified else default"""
		self._taskmaster.reloadPrograms()

	def do_exit(self, line):
		"""exit
		Exit Taskmaster"""
		print ("Supervised programs are stopped")
		self._taskmaster.stopAllProgramsByForce()
		return True

	def do_loglevel(self, line):
		Log.changeLogType(line)
