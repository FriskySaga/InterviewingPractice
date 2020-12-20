/**
 * Firecode Level 3
 * Facebook
 */

// You've recently acquired market prediction superpowers that let you predict the
// closing stock price of an Acme Inc.'s stock a month into the future! To get the
// most out of this superpower, you need to write a function called max_profit that
// takes in an array of integers representing the close out stock price on a given
// day. This function should return the maximum profit you can make out of trading
// Acme Inc.'s stock. There are a few limitations, however:

// 1) You must sell your current holding before buying another - i.e. You may not
//    buy and then buy again. It needs to be a buy - sell - buy - sell ... pattern.

// 2)  You may complete as many transactions as you like. You're using an awesome
//     service like Robinhood, and so there are no transaction costs!

// 3) If you're enormously unlucky (or karma takes over) and no profit can be made,
//    return 0.

// Eg:
// [50,100,20,80,20] => 110
// buy 50, sell for 100, profit is 50
// buy 20, sell for 80, profit is 60
// don't buy again

// [100,50] => 0
// if i buy 100, i will sell at a loss of -50 on the next day

// [50,100,50,100,50] => 100
// buy 50, sell for 100, profit is 50
// buy 50, sell for 100, profit is 50
// don't buy again

#include <cassert>

// The key here is that it is always beneficial to buy
// if the next day's stock price is higher,
// because we assume we can buy and sell stocks on the same day.
// E.g., [80, 100, 110] => 30
// We don't need to hold out to sell on 110.
// We can sell at 100, and then buy 100 to sell for 110
int maxProfit(int prices[], int sz)
{
  int profit = 0;
  for (int i = 1; i < sz; ++i)
  {
    int priceDiff = prices[i] - prices[i-1];
    if (priceDiff > 0) profit += priceDiff;
  }
  return profit > 0 ? profit : 0;
}

int main()
{
  int a[5] = {50,100,20,80,20};
  assert(maxProfit(a, 5) == 110);
  int b[2] = {100,50};
  assert(maxProfit(b, 2) == 0);
  int c[5] = {50,100,50,100,50};
  assert(maxProfit(c, 5) == 100);
  return 0;
}