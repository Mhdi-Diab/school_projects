import datetime
from Config import Config
class Log:

	INFO = 0
	WARN = 1
	ERROR = 2
	logLevel = 0
	errorToStr = ["INFO", "WARN", "ERROR"]

	@staticmethod
	def changeLogType(type):
		def changeLogfunc(index):
			print ("Log Level set at " + Log.errorToStr[index])
			Config.modifyConfig("logLevel", Log.errorToStr[index])

		if type == "INFO":
			Log.logLevel = Log.INFO
			changeLogfunc(Log.INFO)
		elif type == "WARN":
			Log.logLevel = Log.WARN
			changeLogfunc(Log.WARN)
		elif type == "ERROR":
			Log.logLevel = Log.ERROR
			changeLogfunc(Log.ERROR)
		else:
			print ("Log Level not defined")


	@staticmethod
	def logToFile(text, type):
		if type >= Log.logLevel:
			now = datetime.datetime.now()
			logFile = open('./TaskMaster.log', 'a')
			logFile.write(Log.errorToStr[type] + ": " + now.strftime("%Y%m%dT%H%M%S") + ': ' + text + '\n')
			logFile.close()
