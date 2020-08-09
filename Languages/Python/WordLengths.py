'''
    Kevin Tran
    December 21, 2018
    List Comprehension Practice: Get the Length of Each Word in a Sentence
    
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


# Return a list of integers which specify the length of each word in a sentence,
# but only if the word is not the word "the".
# This function uses list comprehension.
def get_word_length_list_comprehension(sentence):
    words = sentence.split()
    return [len(word) for word in words if word != 'the']


# Return a list of integers which specify the length of each word in a sentence,
# but only if the word is not the word "the".
# This function does not use list comprehension.
def get_word_length_standard(sentence):
    words = sentence.split()
    word_lengths = []
    
    for word in words:
        if word != "the":
            word_lengths.append(len(word))
    return word_lengths


# Return a set of words.
def make_up_words():
    return set([
        'the',
        'quick',
        'brown',
        'fox',
        'jumped',
        'over',
        'fence',
        'lazy',
        'dog',
        'cat',
        'doctor',
        'bright',
        'strawberry',
        'like',
        'that',
        'therefore',
        'nightcore',
        'havana',
        'my',
        'heart',
        'the',
        'friends',
    ])


# Randomly generate a sentence to pass as input.
def make_sentence(words):
    sentence = ""
    max_words = random.randint(1,21)
    
    for x in range(0, max_words):
        sentence += words.pop() + " "
    return sentence


if __name__ == '__main__':
    sentence = make_sentence(make_up_words())
    word_lengths_std = get_word_length_standard(sentence)
    word_lengths_lc = get_word_length_list_comprehension(sentence)
    
    print(sentence)
    print(word_lengths_std)
    print(word_lengths_lc)
    
    assert word_lengths_std == word_lengths_lc, "Both lists are different!"

