/**
 * Firecode Level 4
 * Amazon
 */

// Write a function to determine if it is possible to choose a subset of elements
// from a given array such that the sum of all numbers in the subset is equal to a
// given target. Assume target is always a positive number.

// Examples:
// group_sum({1,2,3,6,5},5,10) ==> true
// group_sum({1,2,3,6,5},5,18) ==> false
bool find_sum(int startindx, int arr[], int sz, int target)
{
    if (target == 0)            
      return true;
    if (startindx >= sz)        /* Return when read the entire array */
      return false;
    /* Calculate the sum by including the element at startindx */
    if (find_sum(startindx+1, arr, sz, target-arr[startindx]))
      return true;
    else   /* Calculate the sum without the element at startindx */
      return find_sum(startindx+1, arr, sz, target);
}

bool group_sum(int arr[], int size, int target)
{
    if (size <= 0) 
      return 0;
    return find_sum(0, arr, size, target);
}

// Same problem as above, but with one extra criteria:
// The subset to sum must contain the value stored by `must_have`
bool group_sum_with_num(int arr[], int sz, int must_have, int target_sum)
{
  if (target_sum == 0) return true;
  else if (sz == 0) return false;
  else
  {
    if (arr[sz-1] == must_have)
      return group_sum_with_num(arr, sz-1, must_have, target_sum-must_have);
    else
    {
      // Calculate sum with element at last index
      if (group_sum_with_num(arr, sz-1, must_have, target_sum-arr[sz-1]))
        return true;

      // Calculate sum without element at last index
      else
        return group_sum_with_num(arr, sz-1, must_have, target_sum);
    }
  }
}
