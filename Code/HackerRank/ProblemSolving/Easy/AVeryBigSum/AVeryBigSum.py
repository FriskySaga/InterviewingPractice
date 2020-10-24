"""HackerRank (Easy): A Very Big Sum

Problem Solving - Algorithms
"""

def aVeryBigSum(ar: list[int]) -> int:
  """Compute the sum of the given list of integers.
  :param ar: Integers to sum
  :return: The sum
  """
  return sum(ar)

if __name__ == '__main__':
  assert aVeryBigSum([1000000001,1000000002,1000000003,1000000004,1000000005]) == 5000000015

