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

def matchSpecificCharacters(s: str) -> bool:
  """Match a string S with the following conditions:
  - S must be of length 6
  - First character: 1, 2, or 3
  - Second character: 1, 2, or 0
  - Third character: x, s, or 0
  - Fourth character: 3, 0, A, or a
  - Fifth character: x, s, or u
  - Sixth character: . or ,
  """
  return re.search('^[1-3][0-2][xs0][30Aa][xsu][.,]$', s)

def matchSpecificCharactersViaExclusion(s: str) -> bool:
  """Match a string S with the following conditions:
  - S must be of length 6
  - First character: Non-digit
  - Second character: Non-lowercase vowel
  - Third character: Cannot be b, c, D, or F
  - Fourth character: Non-whitespace character
  - Fifth character: Non-uppercase vowel
  - Sixth character: Not . or ,
  """
  return re.search('^\D[^aeiou][^bcDF]\S[^AEIOU][^.,]$', s)

def matchCharacterRanges(s: str) -> bool:
  """Match a string S that satisfies the criteria:
  - S must be at least of length 5
  - First character: Lowercase English alphabetic character
  - Second character: Positive digit
  - Third character: Non-lowercase English alphabetic character
  - Fourth character: Non-uppercase English alphabetic character
  - Fifth character: Uppercase English alphabetic character
  """
  return re.search('^[a-z][1-9][^a-z][^A-Z][A-Z]*', s)

def matchCharacterRepetitions(s: str) -> bool:
  """Match a string S that satisfies the following criteria:
  - S must be of length 45
  - The first 40 characters should consist of letters or even digits
  - The last 5 characters should consist of odd digits or whitespace
  """
  return re.search('^([A-Z]|[a-z]|[02468]){40}([0-9]|\s){5}$', s)

if __name__ == "__main__":
  assert matchCharacterRepetitions('2222222222aaaaaaaaaa2222222222aaaaaaaaaa13 57')
  assert matchCharacterRanges('m5[tLyy')
  assert matchSpecificCharactersViaExclusion('aUeky?')
  assert matchSpecificCharacters('32sau.')
  assert matchWordCharacters('www.hackerrank.com')
  assert matchWhitespaceCharacters('08 14 20')
  assert matchDigitCharacters('06-11-2015')
  assert matchSpecificString('the hackerrank team')
  assert matchNonNewLine('abc.def.ghi.jkx')

