'''
    Kevin Tran
    May 30, 2019
    To understand the subprocess module in Python
'''

import subprocess


# Open the batch file for Windows!
cmdStr = ['start', 'hello.bat']
pipe = subprocess.Popen(cmdStr,
                        cwd = 'H:\\GitHub\\schoolwork\\python-subprocess',
                        stdout = subprocess.PIPE,
                        stderr = subprocess.PIPE,
                        shell = True) # remember to include env
pipe.communicate()
if pipe.returncode == 0:
    print "Success!\n"
else:
    print "No success!\n"


# # Open the shell file for Linux!
# cmdStr = ['./hello.sh']
# pipe = subprocess.Popen(cmdStr,
#                         cwd = '/mnt/h/GitHub/schoolwork/python-subprocess')
# pipe.communicate()
# if pipe.returncode == 0:
#     print "Success!"
# else:
#     print "Failed!'"

# cmdStr = 'ps -ef | grep ' + 

# To kill a Linux shell process
# ps (process status) provides information about the currently running processes, include PIDs
# e lists all processes of all users
# f is "full"
# grep (globally search a regular expression and print)
# v prints shell input lines as they are read
# awk is a programming language designed for processing text-based data
# print$2 shows the 2nd field, which should be the PID from "ps -ef"
# xargs is a command on Unix and most Unix-like operating systems used to build and execute commands from standard input
# kill 9 doesn't kill the process cleanly
cmdStr = "ps -ef | grep Simulator | grep -v grep | awk '{print$2}' | xargs kill -9"

