/**
 * Firecode - Level 3
 * MachineZone
 */

// A Range Module is a module that tracks ranges of numbers. Range modules are used
// extensively when designing scalable online game maps with millions of players.
// Your task is to write a method - merge_intervals that takes in a vector of
// integer Intervals (aka ranges), and returns a vector of sorted Intervals where
// all overlapping intervals have been merged.

// Note:
// a) [1,3] represents an interval that includes 1, 2 and 3.
// b) Intervals should be sorted based on the value of start

// Examples:

// Input: [ [1,3], [2,5] ]
// Output: [ [1,5] ]

// Input: [ [3,5], [1,2] ]
// Output: [ [1,2], [3,5] ]

#include <algorithm>
#include <iostream>
#include <vector>

class Interval
{
public:
  int start;
  int end;
  Interval(){}
  Interval(int start, int end)
  {
    this->start = start;
    this->end = end;
  }
};

void printIntervalsList(const std::vector<Interval>& intervalsList)
{
  for (const auto& x : intervalsList) std::cout << "[" << x.start << "," << x.end << "] ";
  std::cout << std::endl;
}

bool compareIntervals(const Interval& a, const Interval& b)
{
  return a.start < b.start;
}

std::vector<Interval> mergeIntervals(std::vector<Interval> intervalsList)
{
  if (intervalsList.size() <= 1) return intervalsList;
  std::vector<Interval> mergedIntervalsList;
  std::sort(intervalsList.begin(), intervalsList.end(), compareIntervals);
  Interval lastInterval = intervalsList[0];
  for (unsigned int i = 1; i < intervalsList.size(); ++i)
  {
    Interval currentInterval = intervalsList[i];
    if (lastInterval.end >= currentInterval.start)
    {
      lastInterval.end = std::max(lastInterval.end, currentInterval.end);
    }
    else
    {
      mergedIntervalsList.push_back(lastInterval);
      lastInterval = currentInterval;
    }
  }
  mergedIntervalsList.push_back(lastInterval);
  return mergedIntervalsList;
}

int main()
{
  std::vector<Interval> a = mergeIntervals(std::vector<Interval>{Interval(1,3), Interval(2,5)});
  printIntervalsList(a); // [1,5]
  
  std::vector<Interval> b = mergeIntervals(std::vector<Interval>{Interval(3,5), Interval(1,2)});
  printIntervalsList(b); // [1,2], [3,5]

  return 0;
}