/**
 * Firecode Level 4
 * Amazon
 */

// Helper function
int count_coins(int coins[], int n, int amount, int current_coin_index) 
{
  int next_coin_index;
  if (amount == 0)
    return 1;

  // Ran out of the denominations
  if (current_coin_index == -1)
    return 0;
  
  // Keep track of the next coin
  if (current_coin_index < n-1)
    next_coin_index = current_coin_index + 1;
  
  // The current coin is the last coin
  else
    next_coin_index = -1;

  int res = 0;

  // Try different number of coins which can possibly be used add upto the amount
  for (int i = 0; i * coins[current_coin_index] <= amount; ++i)
    res += count_coins(coins, n, amount-i*coins[current_coin_index], next_coin_index);

  return res;
}

// Given an array containing the available denominations of coins in descending
// order, write a function to compute the number of possible ways of representing a
// monetary amount in cents. For simplicity, assume that there are an infinite
// number of coins available for each coin denomination in the array.

// Examples:
// make_change({25,10,5,1}, 4, 10) ==> 4
int make_change(int coins[], int n, int amount) 
{
  if (amount <= 0)
    return 0;
  if (n > 0)
    return count_coins(coins, n, amount, 0);
  return 0;
}

// Alternate solution
// It's a counting combinations but instead of a set size K you're using a target
// value. Also the assumption that there are infinite amount of a given coin is why
// the second call to make_change doesn't decrement the value of n. If amount is
// equal to 0 we know we have added up all the right coins that sum exactly to
// amount, so we return 1 in essence adds 1 to our total.
int make_change(int coins[], int n, int amount)
{
  if (amount == 0)
    return 1;

  if (amount < 0)
    return 0;

  if (n <= 0)
    return 0;

  return make_change(coins, n-1, amount) + make_change(coins, n, amount-coins[n-1]);
}


#include<algorithm>

// Alternate solution dynamic programming
int make_change(int coins[], int n, int amount)
{
  if (amount < 0) return 0;
  
  // Coins should be in assending order
  std::sort(&coins[0],&coins[n-1]);
  
  // Build a solution matrix
  //   0 1 2 3 4 5
  //   _ _ _ _ _ _
  // 0|1 0 0 0 0 0
  // 1|1 1 1 1 1 1
  // 3|1 1 1 2 2 2
  // 5|1 1 1 2 2 3
  //
  // Above is for
  // coins = {1,3,5}, amount = 5

  // https://www.quora.com/What-is-an-easy-way-to-understand-the-coin-change-problem-in-dynamic-programming
  // https://algorithms.tutorialhorizon.com/dynamic-programming-coin-change-problem/

  int solutions[n + 1][amount + 1];

  // All sets from {} to {1,3,5} can make change for amount 0
  for(int i = 0; i <= n; ++i)
  {
    solutions[i][0] = 1;
  }

  // Empty set {} cannot make change for any amount
  for (int j = 1; j <= amount; ++j)
  {
    solutions[0][j] = 0;
  }

  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= amount; ++j)
    {
      if (coins[i - 1] <= j)
      {
        // Add previous solution to
        // (current amount - current coin) solution
        solutions[i][j] = solutions[i - 1][j] + solutions[i][j - coins[i-1]];
      }
      else
      {
        // If current coin larger than current amount, take previous solution
        solutions[i][j] = solutions[i - 1][j];
      }
    }
  }

  return solutions[n][amount];
}