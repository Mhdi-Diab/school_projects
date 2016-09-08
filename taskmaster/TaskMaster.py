import yaml
import os
import signal
import datetime
import ConfigParser
from Program import Program
from Log import Log
from Config import Config

class TaskMaster:
	programs = {}
	detailedStatus = False

	def __init__(self, file):
		Config.initConfig()
		self.readConfig()
		Log.logToFile('TaskMaster started', Log.INFO)
		self.loadConfiguration(file)
		self.startAllPrograms(True)
		self.updateAll();
		self.printProgramsStatus()

	def readConfig(self):
		errorLevel = Config.readConfig('logLevel')
		if errorLevel is not None:
			Log.changeLogType(errorLevel)
		detailedStatus = Config.readConfig('detailedStatus')
		if detailedStatus is not None:
			self.detailedStatus = detailedStatus

	##### Methode appelee en boucle par le thread ######
	def updateAll(self):
		for key, value in self.programs.items():
			value.updateStatus()

	def stopAllPrograms(self):
		startedPrograms = (key for key, value in self.programs.items())
		for key in startedPrograms:
			self.stopProgram(key)
			Log.logToFile(key + ' stopped', Log.INFO)

	def stopAllProgramsByForce(self):
		startedPrograms = (key for key, value in self.programs.items())
		for key in startedPrograms:
			self.programs[key].forceStop()
			Log.logToFile(key + ' stopped', Log.INFO)

	def stopProgram(self, key):
		try:
			self.programs[key].stop()
		except Exception as e:
			print (key + " is not a program")

	def startAllPrograms(self, checkAutoStart = False):
		for key, prog in self.programs.items():
			if ((prog.status == Program.STOPPED or prog.status == Program.NOT_STARTED)
				and (checkAutoStart == False or prog.autostart == True)):
				self.startProgram(key)

	def startProgram(self, key):
		try:
			self.programs[key].start()
		except Exception as e:
			print (key + " is not a program")
		Log.logToFile(key + ' started', Log.INFO)

	def printProgramsStatus(self):
		for key, value in self.programs.items():
			value.printStatus()

	def printProgramsDetailedStatus(self):
		for key, value in self.programs.items():
			value.printDetailedStatus()

	def reloadPrograms(self):
		with open(str(self.file), 'r') as stream:
			dico = yaml.load(stream)
			Log.logToFile('Configuration file reloaded', Log.INFO)
			self.loadProgramsFromYaml(dico)

	def loadConfiguration(self, file_path = None):
		if file_path is None:
			file_path = 'config/default_config.yml'
		self.file = file_path
		with open(str(file_path), 'r') as stream:
			dico = yaml.load(stream)
			Log.logToFile('Configuration file loaded', Log.INFO)
			self.loadProgramsFromYaml(dico)

	def loadProgramsFromYaml(self, dico):
		if 'programs' not in dico.keys():
			print('Missing \'programs\' in configuration file', Log.ERROR)
			return
		programsYaml = dico['programs']
		for prog in programsYaml:
			nb = programsYaml[prog]['numprocs'] if 'numprocs' in programsYaml[prog] else 1
			for i in range(nb):
				name = prog + ':' + prog + '_' + str(i)
				if (name in self.programs):
					self.programs[name].reload(programsYaml[prog])
				else:
					self.programs[name] = Program(name, programsYaml[prog])
