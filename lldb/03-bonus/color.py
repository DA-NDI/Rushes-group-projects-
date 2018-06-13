import lldb

#color func
def color_red(debugger, command, result, internal_dict):
    if debugger.GetSelectedTarget():
        lldb.debugger.HandleCommand('script print "\033[31m"')
def color_default(debugger, command, result, internal_dict):
    if debugger.GetSelectedTarget():
        lldb.debugger.HandleCommand('script print "\033[0m"')
# initialization code to add your commands
def __lldb_init_module(debugger, internal_dict):
	lldb.debugger.HandleCommand('command script add -f color.color_red color_red')
	lldb.debugger.HandleCommand('command script add -f color.color_default color_default')
