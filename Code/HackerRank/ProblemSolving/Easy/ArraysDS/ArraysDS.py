"""HackerRank (Easy): ArraysDS

Problem Solving - Algorithms
"""

def reverseArray(a: list[int]) -> list[int]:
  """Reverse the array.

  :param a: Array of integers to reverse
  :return: The reversed array
  """
  return a[::-1]

if __name__ == '__main__':
  assert reverseArray([1,4,3,2]) == [2,3,4,1]

