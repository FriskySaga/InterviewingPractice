"""Leetcode (Medium): Single Element in a Sorted Array 

Given a sorted array consisting of only integers where every element appears twice except for one element which appears once.
Find this single element that appears only once. 

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10

Your solution should run in O(log n) time and O(1) space.
"""

def solve(nums: list[int]) -> int:
  """Utilize the parity of the index-duplicate mapping.

  Example:
  [2, 2, 7, 7, 8, 9, 9]
   0  1  2  3  4  5  6
  
  If every element in the sorted array were to appear exactly twice, they would occur in pairs at indices i, i+1 for all even i.

  Equivalently, nums[i] = nums[i+1] and nums[i+1] != nums[i+2] for all even i.

  When we insert the unique element into this list, the indices of all the pairs following it will be shifted by one, negating the above relationship.

  So, for any even index i, we can compare nums[i] to nums[i+1].
    If they are equal, the unique element must occur somewhere after index i+1.
    If they aren't equal, the unique element must occur somewhere before index i+1.

  Using this knowledge, we can use binary search to find the unique element.

  We just have to make sure that our pivot index is always even, so we can use mid = 2 * ((lo + hi) // 4) instead of the usual mid = (lo + hi) // 2.

  Credits: cjporteo
  """

  lo, hi = 0, len(nums) - 1

  while lo < hi:
    # Pivot index is even
    mid = 2 * ((lo + hi) // 4)
    # print(lo, mid, hi)

    # Order is maintained, look right
    if nums[mid] == nums[mid+1]:
      lo = mid + 2

    # Order is not maintained, look left
    else:
      hi = mid

  # print()
  return nums[lo]

def attemptOne(nums: list[int]) -> int:
  """Add seen numbers to a frequency array, and remove them if seen again.
  At the end, there should only be one number present.

  Space Complexity: O(2n)
    - The main array, O(n)
    - The freq array that gets added to and removed from, O(n)
  Time Complexity: O(n^2 + 1)
    - Looping through the main array, O(n)
    - Adding to an array,  O(n)
    OR Removing from the array, O(n)
    - Accessing the array at the end, O(1)
  """
  freqList = []
  for x in nums:
    if x not in freqList:
      freqList.append(x)
    else:
      freqList.remove(x)
  return freqList[0]

if __name__ == "__main__":
  #                                                    {lo, mid, hi}
  assert solve([1,1,2,3,3,4,4,8,8]) == 2 # 9 elements, {0,4,8}, {0,2,4}, {0,2,2}
  assert solve([3,3,7,7,10,11,11]) == 10 # 7 elements, {0,2,6}, {4,4,6}
  assert solve([-4, -4, 0]) == 0 # last element unique
  assert solve([1515, 1516, 1516]) == 1515 # first element unique

