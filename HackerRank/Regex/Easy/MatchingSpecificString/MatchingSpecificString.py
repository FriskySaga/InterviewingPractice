"""HackerRank (Easy): Matching Specific String

Match any instance of the string 'hackerrank'. This is case sensitive.
"""

import re

def doRegex(s: str) -> bool:
  pattern = re.compile(r'\b' + 'hackerrank' + r'\b')
  return pattern.search(s)

if __name__ == "__main__":
  assert doRegex('hackerrank')
  assert doRegex('the hackerrank team')
  assert doRegex('hackerrank2') is None
  assert doRegex('failwhale') is None

