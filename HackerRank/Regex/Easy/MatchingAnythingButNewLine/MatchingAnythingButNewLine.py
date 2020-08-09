"""HackerRank (Easy): Matching Anything But New Line

Write a regular expression that matches only and exactly strings of the form:
  abc.def.ghi.jkx

...where each variable:
  a,b,c,d,e,f,g,h,i,j,k,x

...can be any single character except the newline.
"""

import re

if __name__ == "__main__":
  s = input()
  p = re.compile('^.{3}\..{3}\..{3}\..{3}$')
  m = p.match(s)
  if m is not None:
    print('true')

