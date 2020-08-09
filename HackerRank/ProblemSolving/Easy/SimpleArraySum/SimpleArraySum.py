"""HackerRank (Easy): ArraysDS

Problem Solving - Algorithms
"""

def simpleArraySum(ar: list[int]) -> list[int]:
  """Sum the given array.

  :param ar: Array of integers to sum
  :return: The sum
  """
  return sum(ar)

if __name__ == '__main__':
  assert simpleArraySum([1,2,3,4,10,11]) == 31

