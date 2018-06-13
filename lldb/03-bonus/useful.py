import lldb

#USEFUL func
def useful(debugger, command, result, internal_dict):
    lldb.debugger.HandleCommand('script print "\033[35mI am \'USEFUL\' function\033[0m"')
# initialization code to add your commands
def __lldb_init_module(debugger, internal_dict):
	lldb.debugger.HandleCommand('command script add -f useful.useful useful')
