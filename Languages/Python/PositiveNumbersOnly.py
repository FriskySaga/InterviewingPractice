'''
    Kevin Tran
    December 23, 2018
    List Comprehension Practice: Positive Numbers Only
    Practice from https://www.learnpython.org/en/List_Comprehensions

    ++++++++++++++++++++++++++++
    Syntax of List Comprehension
    ----------------------------
    [EXPRESSION for ITEM in LIST if CONDITION]
    
    +++++++++++
    Translation
    -----------
    for ITEM in LIST:
        if CONDITION:
            EXPRESSION
    
    +++++
    Notes
    -----
    1. Do not use your list variable in a list comprehension.
        Ex. [word_lengths.append(len(word)) for word in words if word != 'the']
        Reason: This does not work because of "word_lengths.append()".
'''


import random

# Return a list of only positive numbers from the given list of numbers.
# This function uses list comprehension.
def get_positive_numbers_lc(numbers):
    return [n for n in numbers if n > 0]


# Return a list of only positive numbers from the given list of numbers.
# This function does not use list comprehension.
def get_positive_numbers_standard(numbers):
    ret = []
    for n in numbers:
        if n > 0:
            ret.append(n)
    return ret


# Make a list of random numbers.
def make_numbers():
    numbers = []
    max_num_numbers = random.randint(1,21)

    for x in range(0, max_num_numbers):
        numbers.append(round(random.uniform(-100,100),2))

    return numbers


if __name__ == '__main__':
    numbers = make_numbers()
    numbers_std = get_positive_numbers_standard(numbers)
    numbers_lc = get_positive_numbers_lc(numbers)

    print(numbers)
    print(numbers_std)
    print(numbers_lc)

    assert numbers_std == numbers_lc, "Both lists are different!"

