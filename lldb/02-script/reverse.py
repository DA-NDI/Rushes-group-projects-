import lldb

#reverse func
def ft_reverse(debugger, command, result, internal_dict):
    if debugger.GetSelectedTarget():
        print 'FT_' + str(debugger.GetSelectedTarget())[::-1]
# initialization code to add your commands 
def __lldb_init_module(debugger, internal_dict):        
    lldb.debugger.HandleCommand('command script add -f reverse.ft_reverse reverse')
