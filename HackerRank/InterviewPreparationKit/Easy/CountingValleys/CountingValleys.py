"""HackerRank (Easy): Counting Valleys

Interview Preparation Kit - Warm-up Challenges
"""

# Complete the countingValleys function below.
def countingValleys(n: int, s: str) -> int:
  """Count the number of valleys

  :param n: Number of steps, i.e., length of s
  :param s: Sequence of steps; valid characters are 'U' or 'D'
  :return: The number of valleys

  A valley starts at sea level and ends at sea level.

   12345678
  _/\      _
     \    /
      \/\/
   12345678

  In this figure, there is only one valley which starts at step 3 and ends at step 8.

  This sequence of steps can be described as: 'UDDDUDUU'
  """
  level = numValleys = 0
  for index, value in enumerate(s):
    if value == 'U':
      if level == -1:
        numValleys += 1
      level += 1
    else:
      level -= 1
  return numValleys

if __name__ == '__main__':
  assert countingValleys(8, 'UDDDUDUU') == 1
  assert countingValleys(12, 'DDUUDDUDUUUD') == 2

