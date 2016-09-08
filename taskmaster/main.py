#!/nfs/zfs-student-2/users/atamano/.brew/bin/python
from Program import Program
from Commander import Commander
from TaskMaster import TaskMaster
import sys

######## BONUS ##########
# -	redirect_stderr 	#
# - stop all			#
# - start all			#
# - Log level			#
# - Detailled status	#
# - persistent options	#

def start(argv):
	try:
		file = argv[0] if len(argv) > 0 else "config/default_config.yml"
		taskmaster = TaskMaster(file)
		#Starts main input loop
		commander = Commander()
		commander.setTaskmaster(taskmaster)
		commander.cmdloop()
	except (KeyboardInterrupt, SystemExit):
		taskmaster.stopAllPrograms()
	except Exception as e:
		pass

if __name__ == '__main__':
	start(sys.argv[1:])
