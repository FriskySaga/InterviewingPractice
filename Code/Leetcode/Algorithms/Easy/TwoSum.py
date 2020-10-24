"""Leetcode (Easy): Two Sum 

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
"""

def bruteForce(nums: list[int], target: int) -> list[int]:
  for i in range(len(nums)):
    for j in range(i+1, len(nums)):
      if nums[i] + nums[j] == target:
        return [i,j]

def twoPassHashTable(nums: list[int], target: int) -> list[int]:
  hashTable = {}

  # Build the hash table
  for idx, val in enumerate(nums):
    hashTable[val] = idx
  
  # Is the complement is in the hash table? O(n)
  for idx, val in enumerate(nums):
    complement = target - val
    if complement in hashTable and hashTable[complement] != idx:
      return [idx,hashTable[complement]]

def twoSum(nums: list[int], target: int) -> list[int]:
  hashTable = {}

  # Build the hash table and look to the back for a complement
  for idx, val in enumerate(nums):
    complement = target - val
    if complement in hashTable:
      return [hashTable[complement],idx]
    hashTable[val] = idx

if __name__ == '__main__':
  assert twoSum([2,7,11,15], 9) == [0,1]

