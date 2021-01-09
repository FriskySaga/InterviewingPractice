/**
 * Firecode Level 4
 * Amazon
 */

// Write a function to determine if it is possible to choose a subset of elements from a given array such that the sum of all numbers in the subset is equal to a given target.
// Assume target is always a positive number.

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

// Add any helper functions(if needed) above.
bool group_sum(int arr[], int size, int target)
{
    if (size <= 0) 
      return 0;
    return find_sum(0, arr, size, target);
}

// alternate solution
bool group_sum_with_num(int arr[], int sz, int must_have, int target_sum) {
    if (target_sum == 0)
        return true;
    else if (sz==0)
        return false;
    else{
      if (arr[sz-1] == must_have)  /* Calculating the sum by Including must have element */
        return group_sum_with_num(arr, sz-1, must_have, target_sum-must_have);
       else{                       /* Calculating the sum by Including element at last indx */
         if (group_sum_with_num(arr, sz-1, must_have, target_sum-arr[sz-1]))
           return true;
         else                     /* Calculate the sum without the element at last indx */
           return group_sum_with_num(arr, sz-1, must_have, target_sum);
       }
    }
}