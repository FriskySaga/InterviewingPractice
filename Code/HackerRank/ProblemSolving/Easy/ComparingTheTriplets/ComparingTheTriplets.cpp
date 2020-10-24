/**
 * Comparing the Triplets
 * https://www.hackerrank.com/challenges/compare-the-triplets/problem
 * Easy Algorithms
 *
 * Alice's Scores: 17 28 30
 * Bob's Scoers:   99 16 8
 *
 * Alice's Wins: 2
 * Bob's   Wins: 1
 * 
 * Output: 2 1
 */

#include <cassert>
#include <cstdint>
#include <vector>

using namespace std;

vector<int> compareTriplets(vector<int> a, vector<int> b)
{
  uint16_t score1 = 0, score2 = 0;
  for (uint16_t i = 0U; i < a.size(); ++i)
  {
    if (a[i] < b[i]) ++score2;
    else if (a[i] > b[i]) ++score1;
  }
  return vector<int>{score1, score2};
}

int main()
{
  vector<int> aliceScores = {17, 28, 30};
  vector<int> bobScores = {99, 16, 8};
  vector<int> answer{2, 1};
  assert (compareTriplets(aliceScores, bobScores) == answer);
}

