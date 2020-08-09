'''
    Kevin Tran
    December 20, 2018
    Fall 2016 COP3223H Program #3 w/ Arup Guha
    Tallying Votes
    http://www.cs.ucf.edu/~dmarino/ucf/transparency/cop3223/asgn-python/Election-sorting.pdf
    
    To run this program, pass in the input file name.

    An example input file is shown at the very bottom.
'''


import sys


# Given constraints from problem statement.
# Also, no two candidates will have the same number of votes.
MAX_VOTES = 300000000
MAX_CANDIDATES = 100


def check_rep(d):
    higher = MAX_VOTES
    for k,v in d:
        assert v <= higher, "%s is not lower than their precedent." % k
        higher = v


def get_file_name():
    if len(sys.argv) == 2:
        return sys.argv[1]
    elif len(sys.argv) < 2:
        file_name = None
        while file_name == None:
            file_name = input("Type in the name of the input file: ")
        return file_name


def open_file(file_name, mode):
    try:
        return open(file_name, mode)
    except IOError:
        print("**IOERROR: File could not be opened.**")
        sys.exit()


def parse_input(fp):
    vote_dict = {}
    text = fp.read()
    vote_info = text.split()
    for i in range(0, len(vote_info), 2):
        candidate_name = vote_info[i]
        candidiate_votes = int(vote_info[i+1])
        if vote_dict.get(candidate_name) != None: # if old candidate
            vote_dict[candidate_name] += candidiate_votes
        else:
            vote_dict[candidate_name] = candidiate_votes
    return vote_dict


def print_tuple_list(d):
    for k, v in d:
        print("%s %s" % (k,v))


def read_input():
    fp = open_file(get_file_name(), 'r')
    return parse_input(fp)


# Sort by value in descending order.
def sort_candidates(d):
    # List comprehension method
    # return [(k, d[k]) for k in sorted(d, key=d.get, reverse=True)]
    
    # Non-list comprehension method
    sorted_dict_list = []
    
    # Pass in the dictionary 'd' into sorted().
    # Sort by the key 'd.get'. In other words, sort by value.
    # get() returns the value for a given key.
    # By default, sorted sorts in ascending order. So we need to reverse that.
    for k in sorted(d, key=d.get, reverse=True):
        sorted_dict_list.append((k, d[k]))
    return sorted_dict_list


# Display the candidate names and their votes in descending order.
def tally_votes():
    sorted_dict_list = sort_candidates(read_input())
    print_tuple_list(sorted_dict_list)
    return sorted_dict_list


# ==============================================================================
# SOFTWARE ENGINEERING SECTION ABOVE (check_rep() is above too)
# ******************************************************************************
# SOFTWARE TESTING SECTION BELOW
# ==============================================================================


# Wrapper test function.
def test_code():
    test1()
    
    # Notes: (I might revisit this program in the future and make it more robust
    #         but for now, I'm bored with this program, and I want to move on.)
    #   1. Negative numbers work with this program, but votes are guaranteed to
    #      be positive.
    #   2. Floats do not work. There is no error handling for floats.
    #   3. Numbers higher than 300000000 will mess up the program. I haven't yet
    #      decided whether I want to address this.
    #   4. Duplicate votes are guaranteed to not be in the input file. But I
    #      haven't done any duplicate vote error handling. I'm kinda lazy.


# Ensure my check_rep() function makes sure the final list is sorted in descending order.
def test1():
    sorted_dict_list.append(('Kevin', 300000000))
    print()
    print_tuple_list(sorted_dict_list)
    check_rep(sorted_dict_list)


if __name__ == '__main__':
    sorted_dict_list = tally_votes()
    check_rep(sorted_dict_list)
    
    ### COMMENT OUT IF NOT TESTING CODE ###
    # test_code()

'''
Example Input:

Allie 10 Bill 3
Allie 5 Carmen 7
Carmen 2
Bill 1
Allie 22
Jimmy 17
Oscar 20
Ozpin 5000
Ruby 63
Glenn 0
Goodwitch 4
Glynda 90
Qrow 22
Shel 15
Cathy 19
DJ 55
Alex 94
Bakugo 88
Deku 203
John 34 Jonathan 237
Shorty 7004
SickBoy 35900
Chester 290003 Oobleck 173972
Samantha 30000000 Foster 9999999
'''