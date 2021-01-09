/**
 * Firecode Level 4
 * Amazon
 */

// Given an array containing the available denominations of coins in descending order, write a function to compute the number of possible ways of representing a monetary amount in cents.
//  For simplicity, assume that there are an infinite number of coins available for each coin denomination in the array.

// Examples:

// make_change({25,10,5,1}, 4, 10) ==> 4


int count_coins(int coins[],int n, int amount, int current_coin_index) 
{
    int next_coin_index;
    if (amount == 0)      
        return 1;
    if (current_coin_index == -1)       /* Ran out of the denominations */
        return 0;
    if (current_coin_index < n-1)       /* Keep a track of the next coin */
        next_coin_index = current_coin_index + 1;
    else                                /* the current coin is last coin */
       next_coin_index = -1;
    int res = 0;
     /* Try different number of coins which can possibly be used add upto the amount*/
    for (int i = 0; i * coins[current_coin_index] <= amount; i++)
        res += count_coins(coins,n, amount-i*coins[current_coin_index],next_coin_index);
    return res;
}
// Add any helper functions(if needed) above.
int make_change(int coins[], int n, int amount) 
{
    if (amount<=0 ) 
         return 0;
    if (n > 0)
        return count_coins(coins,n,amount,0);
    return 0;
}