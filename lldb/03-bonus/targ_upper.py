import lldb

def targ_upper(debugger, command, result, dict):
	if debugger.GetSelectedTarget():
        	print str(debugger.GetSelectedTarget()).upper()
def targ_lower(debugger, command, result, dict):
	if debugger.GetSelectedTarget():
        	print str(debugger.GetSelectedTarget()).lower()

def __lldb_init_module(debugger, internal_dict):
        debugger.HandleCommand('command script add -f targ_upper.targ_upper upper')
        debugger.HandleCommand('command script add -f targ_upper.targ_upper lower')
