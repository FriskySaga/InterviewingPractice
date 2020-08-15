"""HackerRank (Easy): All Problems
"""

import re

def matchingSpecificString(s: str) -> bool:
  """Match any instance of the string 'hackerrank'. This is case sensitive.
  """
  pattern = re.compile(r'\b' + 'hackerrank' + r'\b')
  return pattern.search(s)

def matchingAnythingButNewLine(s: str) -> bool:
  """Match only and exactly strings of the form:
    abc.def.ghi.jkx

  ...where each variable:
    a,b,c,d,e,f,g,h,i,j,k,x

  ...can be any single character except the newline.
  """
  pattern = re.compile('^.{3}\..{3}\..{3}\..{3}$')
  return pattern.search(s)


def matchingDigitsAndNonDigitCharacters(s: str) -> bool:
  """Match the pattern:
    xxXxxXxxxx

  Let:
    x denote a digit character
    X denote a non-digit character
  """
  pattern = re.compile('\d\d\D\d\d\D\d\d\d\d')
  return pattern.search(s)

if __name__ == "__main__":
  assert matchingSpecificString('hackerrank')
  assert matchingSpecificString('the hackerrank team')
  assert matchingSpecificString('hackerrank2') is None

  assert matchingAnythingButNewLine('abc.def.ghi.jkx')
  assert not matchingAnythingButNewLine(' abc.def.ghi.jkx ')

  assert matchingDigitsAndNonDigitCharacters('06-11-2015')
  assert not matchingDigitsAndNonDigitCharacters('06-11-201')