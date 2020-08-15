"""HackerRank (Easy): Matching Anything But New Line

Write a regular expression that matches only and exactly strings of the form:
  abc.def.ghi.jkx

...where each variable:
  a,b,c,d,e,f,g,h,i,j,k,x

...can be any single character except the newline.
"""

import re

def doRegex(s: str) -> bool:
  pattern = re.compile('^.{3}\..{3}\..{3}\..{3}$')
  return pattern.match(s)

if __name__ == "__main__":
  assert doRegex('abc.def.ghi.jkx')
  assert not doRegex(' 1abc.def.ghi.jkx ')
  assert not doRegex('ab.def.ghi.jkx')

