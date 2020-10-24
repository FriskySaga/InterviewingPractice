'''
    Kevin Tran
    July 7, 2019

    Messing around with regex in Python
'''

import re

s = ("Teenager Soma Yukihira aspires to become a full-time chef in his" +
     " father Joichiro's family restaurant and surpass his father's culinary" +
     " skills, but Joichiro gets a new job that requires him to travel" +
     " around the world, and closes his shop. Joichiro has Soma enroll " +
     " in Totsuki Saryo Culinary Institute, an elite culinary school where" +
     " students engage in food competitions called shokugeki (anime: food war)." +
     " He secures himself a spot at the school, despite the objections of" +
     " Erina Nakiri, the talented granddaughter of the school's dean." +
     " Soma is assigned to Polaris Dormitory where he meets other aspiring" +
     " chefs, including Megumi Tadokoro. The story follows his adventures" +
     " as he interacts with his peers and challenges Totsuki's students" +
     " as well as others in shokugeki competitions. This excerpt came" +
     " from Wikipedia. Further more, I need some numbers for this test" +
     " string, so I will, use numbers such as 1, 2, 11, 4113, 0, and -3.")

y = 'aaaaaa'

# Use \b as a word boundary to match the empty string
# The IGNORECASE flag can be written as re.I
print len(re.findall(r"\bthe\b", s, re.I)) == 9 # The word "the"

# Use . to match any character except newline.
print re.findall(r"chef.", s) # Any references to toasters

# Use | as an OR operator.
print re.findall(r"Soma Yukihira|Soma|Yukihira", s) # All references of Soma

# Use * to indicate 0 more characters.
print re.findall(r"a*", y)

