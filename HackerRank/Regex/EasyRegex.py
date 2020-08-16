"""HackerRank (Easy): All Problems
"""

import re

def matchNonNewLine(s: str) -> bool:
  """Match only and exactly strings of the form:
    abc.def.ghi.jkx

  ...where each variable:
    a,b,c,d,e,f,g,h,i,j,k,x

  ...can be any single character except the newline.
  """
  return re.search('^.{3}\..{3}\..{3}\..{3}$', s)

def matchSpecificString(s: str) -> bool:
  """Match any instance of the string 'hackerrank'. This is case sensitive.
  """
  return re.search(r'\b' + 'hackerrank' + r'\b', s)

def matchDigitCharacters(s: str) -> bool:
  """Match the pattern:
    xxXxxXxxxx

  Let:
    x denote a digit character
    X denote a non-digit character
  """
  return re.search('\d\d\D\d\d\D\d\d\d\d', s)

def matchWhitespaceCharacters(s: str) -> bool:
  """Match the pattern:
    XXxXXxXX

  Let:
    x denote a whitespace character
    X denote a non-whitespace character
  """
  return re.search('\S\S\s\S\S\s\S\S', s)

def matchWordCharacters(s: str) -> bool:
  """Match the pattern:
    xxxXxxxxxxxxxxXxxx
  
  Note: There are 10 x's in the middle.

  Let:
    x denote a word character
    X denote a non-word character
  """
  return re.search('\w\w\w\W\w\w\w\w\w\w\w\w\w\w\W\w\w\w', s)

if __name__ == "__main__":
  assert matchNonNewLine('abc.def.ghi.jkx')
  assert not matchNonNewLine(' abc.def.ghi.jkx ')

  assert matchSpecificString('the hackerrank team')
  assert matchDigitCharacters('06-11-2015')
  assert matchWhitespaceCharacters('08 14 20')
  assert matchWordCharacters('www.hackerrank.com')

