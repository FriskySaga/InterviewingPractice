'''
    Kevin Tran
    November 15, 2018

    Problem Set 4 - Fuzzer

    Some of the code below comes from Charlie Miller, as mentioned below,
    but other parts of this code comes from Udacity course, Software Testing,
    taught by Dr. John Regehr, who is a Professor at the University of Utah.
'''

#!/usr/bin/python

# 5-line fuzzer below is from Charlie Miller's
# "Babysitting an Army of Monkeys":
# Part 1 - https://www.youtube.com/watch?v=Xnwodi2CBws
# Part 2 - https://www.youtube.com/watch?v=lK5fgCvS2N4

# List of files to use as initial seed
file_list = [
    "Intuition.pdf",
    "RubyNotesForProfessionals.pdf",
    "pa1.pdf",
    "propositional-logic-1.pdf"
]

# List of applications to test
apps = [
    "C:/Program Files (x86)/Adobe/Acrobat Reader DC/Reader/AcroRd32.exe"
]

fuzz_output = "fuzz.pdf"

FuzzFactor = 250
num_tests = 20 # original number was 10000

########## end configuration ##########

import math
import random
import string
import subprocess
import time

for i in range(num_tests):
    # choose a random file and choose a random PDF application
    file_choice = random.choice(file_list)
    app = random.choice(apps)

    # store all bytes from the file into a buffer
    buf = bytearray(open(file_choice, 'rb').read())

    # start Charlie Miller code
    # randomly determine number of writes based on FuzzFactor
    # as FuzzFactor increases, number of random writes decreases
    num_writes = random.randrange(math.ceil((float(len(buf)) / FuzzFactor))) + 1

    # create a random byte and choose from our buffer one of the bytes
    # that will be overwritten with the random byte
    for j in range(num_writes):
        rbyte = random.randrange(256)
        rn = random.randrange(len(buf))
        buf[rn] = "%c"%(rbyte)
    # end Charlie Miller code

    # write all of our new bytes to a new file
    open(fuzz_output, 'wb').write(buf)

    # log what we've done
    print "Using app: %s orig_file: %s #writes=%d" % \
            (app, file_choice, num_writes)

    # open our application with the new file
    process = subprocess.Popen([app, fuzz_output])

    # report results to the console
    time.sleep(1)
    crashed = process.poll()
    if not crashed:
        print "Did not crash"
        process.terminate()
    else:
        print "Attempt #%d crashed!" % (i+1)
        print "Application: %s" % app
        print "Return code: %s" % process.returncode
    time.sleep(1)

