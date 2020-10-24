"""HackerRank (Easy): Sock Merchant

Interview Preparation Kit - Warm-up Challenges
"""

from collections import Counter

def attemptOne(n, ar):
  seenColorsSet = set()
  numMatchingSocks = 0
  for x in ar:
    if x not in seenColorsSet:
      seenColorsSet.add(x)
    else:
      seenColorsSet.remove(x)
      numMatchingSocks = numMatchingSocks + 1
  return numMatchingSocks

# Complete the sockMerchant function below.
def sockMerchant(n: int, ar: list[int]) -> int:
  """
  :param n: The number of socks
  :param ar: The colors of the socks

  :return: The number of matching pairs of socks

  Sample Input:
    9
    10 20 20 10 10 30 50 10 20

  There are 3 pairs of matching socks.
    (10,10), (20,20), (10,10)

  Solution:
    socksCounter: Lists the number of occurrences of each value.
      Counter({10: 4, 20: 3, 30: 1 , 50: 1})
    Use floor division to determine the number of pairs.
  """
  socksCounter, numPairs = Counter(ar), 0
  for color in socksCounter:
    numPairs += socksCounter[color] // 2
  return numPairs

if __name__ == '__main__':
  assert sockMerchant(9, [10,20,20,10,10,30,50,10,20]) == 3
  assert sockMerchant(10, [1,1,3,1,2,1,3,3,3,3]) == 4

