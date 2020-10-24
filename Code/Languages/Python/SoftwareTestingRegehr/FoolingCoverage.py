'''
    Kevin Tran
    November 11, 2018

    Most of this code is taken from the Udacity course, Software Testing, taught
    by Dr. John Regehr, who is a Professor at the University of Utah.

    I was responsible for modifying the test1() and test2() functions to meet
    the specifications.
'''

# SPECIFICATION:
#
# The stats function computes some basic statistics functions
# when given a list of numbers as input.
#
# TASK:
#
# Achieve full statement coverage on the stats function. 
# You will need to:
# 1) Insert a bug into the stats function.
# 2) Modify test1 so that it still achieves full test 
#    coverage, but does not trigger your bug. Depending 
#    on the bug you insert, you may not need to modify 
#    test1 at all.
# 3) Write test2 so that it also achieves full test 
#    coverage, but does trigger your bug.

import math

# Insert a bug of your choosing into the stats function.
def stats(lst):
    min = None
    max = None
    freq = {}
    for i in lst:
        if min is None or i < min:
            min = i
        # I chose to insert my bug here, such that max is set equal to the last
        # number in the list that is not min.
        if max is None or i > min:
            max = i
        if i in freq:
            freq[i] += 1
        else:
            freq[i] = 1
    lst_sorted = sorted(lst)
    if len(lst_sorted)%2 == 0:
        middle = len(lst_sorted)/2
        median = (lst_sorted[middle] + lst_sorted[middle-1]) / 2
    else:
        median = lst_sorted[len(lst_sorted)/2]
    mode_times = None
    for i in freq.values():
        if mode_times is None or i > mode_times:
            mode_times = i
    mode = []
    for (num, count) in freq.items():
        if count == mode_times:
            mode.append (num)
    print "list = " + str(lst)
    print "min = " + str(min)
    print "max = " + str(max)
    print "median = " + str(median)
    print "mode(s) = " + str(mode)

# test1 should achieve full statement coverage of 
# the stats function without triggering the bug 
# you've inserted into the stats function.
def test1():
    ###Your test1 code here. Depending on what 
    # bug you choose to put in the stats function, 
    # you may or may not need to modify test1.
    l = [31, 24, 44, 44]
    stats(l)
    l = [3, 7, 11]
    stats(l)

# test2 should also achieve full statement coverage 
# of the stats function, but should trigger the bug 
# you've inserted into the stats function.
def test2():
    ###Your test2 code here.
    l = [31, 24, 44, 44]
    stats(l)
    # This test case fails because max = 7, which is wrong.
    l = [11, 3, 7]
    stats(l)

test1()
test2()

