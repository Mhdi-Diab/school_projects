import ConfigParser

class Config:
	configFileName = ".TaskMaster.cfg"

	@staticmethod
	def initConfig():
		cfg = ConfigParser.ConfigParser()
		cfg.read(Config.configFileName)
		if not cfg.has_section('TaskMaster'):
			cfg.add_section('TaskMaster')
			f = open(Config.configFileName, 'w')
			cfg.write(f)
			f.close()

	@staticmethod
	def modifyConfig(key, value):
		cfg = ConfigParser.ConfigParser()
		cfg.read(Config.configFileName)
		cfg.set('TaskMaster', key, value)
		f = open(Config.configFileName, 'w')
		cfg.write(f)
		f.close()

	@staticmethod
	def readConfig(key):
		cfg = ConfigParser.ConfigParser()
		cfg.read(Config.configFileName)
		if cfg.has_option('TaskMaster', key):
			return cfg.get('TaskMaster', key)
		else:
			return None
