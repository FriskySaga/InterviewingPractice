"""HackerRank: All Regex Problems
"""

import re

def matchNonNewLine(s: str) -> bool:
  """Match only and exactly strings of the form:
    abc.def.ghi.jkx

  ...where each variable:
    a,b,c,d,e,f,g,h,i,j,k,x

  ...can be any single character except the newline.
  """
  return re.search(r'^.{3}\..{3}\..{3}\..{3}$', s)

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
  return re.search(r'\d\d\D\d\d\D\d\d\d\d', s)

def matchWhitespaceCharacters(s: str) -> bool:
  """Match the pattern:
    XXxXXxXX

  Let:
    x denote a whitespace character
    X denote a non-whitespace character
  """
  return re.search(r'\S\S\s\S\S\s\S\S', s)

def matchWordCharacters(s: str) -> bool:
  """Match the pattern:
    xxxXxxxxxxxxxxXxxx
  
  Note: There are 10 x's in the middle.

  Let:
    x denote a word character
    X denote a non-word character
  """
  return re.search(r'\w\w\w\W\w\w\w\w\w\w\w\w\w\w\W\w\w\w', s)

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
  return re.search(r'^[1-3][0-2][xs0][30Aa][xsu][.,]$', s)

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
  return re.search(r'^\D[^aeiou][^bcDF]\S[^AEIOU][^.,]$', s)

def matchCharacterRanges(s: str) -> bool:
  """Match a string S that satisfies the criteria:
  - S must be at least of length 5
  - First character: Lowercase English alphabetic character
  - Second character: Positive digit
  - Third character: Non-lowercase English alphabetic character
  - Fourth character: Non-uppercase English alphabetic character
  - Fifth character: Uppercase English alphabetic character
  """
  return re.search(r'^[a-z][1-9][^a-z][^A-Z][A-Z]*', s)

def matchCharacterRepetitions(s: str) -> bool:
  """Match a string S that satisfies the following criteria:
  - S must be of length 45
  - The first 40 characters should consist of letters or even digits
  - The last 5 characters should consist of odd digits or whitespace
  """
  return re.search(r'^([A-Z]|[a-z]|[02468]){40}([0-9]|\s){5}$', s)

def matchXYRepetitions(s: str) -> bool:
  """Match a string S that meets these conditions:
  - S should begin with 1 or 2 digits
  - After that, S should have 3 or more letters
  - Then S should end with [0,3] . symbols.
  """
  return re.search(r'^\d{1,2}([a-z]|[A-Z]){3,}\.{0,3}$', s)

def matchZeroOrMoreRepetitions(s: str) -> bool:
  """Match a string S that...
  - Begins with at least 2 digits
  - After that, S should have 0 more lowercase characters
  - S should end with 0 or more uppercase letters
  """
  return re.search(r'^\d{2,}[a-z]*[A-Z]*$', s)

def matchOneOrMoreRepetitions(s: str) -> bool:
  """Match a string S that...
  - Begins with 1 or more digits
  - Have 1 or more uppercase letters
  - End with 1 or more lowercase letters
  """
  return re.search(r'^\d+[A-Z]+[a-z]+$', s)

def matchWordBoundaries(s: str) -> bool:
  """Match a string S that...
  - Can be of any length
  - Starts with a word boundary followed by a vowel
  - Contains only letters
  - Ends with a word boundary
  """
  return re.search(r'\b[aeiouAEIOU][a-zA-Z]*\b', s)

def captureGroups(s: str) -> bool:
  """Match a string S that...
  - Has at least 3 consecutive repetitions of 'ok'
  """
  return re.search(r'(ok){3}', s)

def matchSameTextAgain(s: str) -> bool:
  """Match a string S that...
  - Length 20
  1. lowercase letter
  2. word character
  3. whitespace character
  4. non-word character
  5. digit
  6. non-digit
  7. uppercase letter
  8. letter
  9. vowel
  10. non-whitespace character
  Rinse & repeat for remaining 10 characters
  """
  return re.search(r'([a-z]\w\s\W\d\D[A-Z][a-zA-Z][aeiouAEIOU]\S)\1', s)

def backreferenceToFailedGroups(s: str) -> bool:
  """Match a string S that...
  - Consists of 8 digits
  - May have a "-" separator such that S gets divided in sets of 2 digits
  """
  return re.search(r'(\d{8}|\d{2}', s)

if __name__ == "__main__":
  assert backreferenceToFailedGroups('12345678')
  # assert backreferenceToFailedGroups('12-34-56-78')
  assert matchSameTextAgain('ab #1?AZa$ab #1?AZa$')
  assert captureGroups('hiokokok43')
  assert matchWordBoundaries('Found any match?')
  assert matchOneOrMoreRepetitions('18Grad')
  assert matchZeroOrMoreRepetitions('14')
  assert matchXYRepetitions('3threeormorealphabets.')
  assert matchCharacterRepetitions('2222222222aaaaaaaaaa2222222222aaaaaaaaaa13 57')
  assert matchCharacterRanges('m5[tLyy')
  assert matchSpecificCharactersViaExclusion('aUeky?')
  assert matchSpecificCharacters('32sau.')
  assert matchWordCharacters('www.hackerrank.com')
  assert matchWhitespaceCharacters('08 14 20')
  assert matchDigitCharacters('06-11-2015')
  assert matchSpecificString('the hackerrank team')
  assert matchNonNewLine('abc.def.ghi.jkx')

