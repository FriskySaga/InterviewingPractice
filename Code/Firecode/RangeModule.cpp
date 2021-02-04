/**
 * MachineZone
 * A Range Module is a module that tracks ranges of numbers. Range modules are used
 * extensively when designing scalable online game maps with millions of players.
 */

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

// Firecode - Level 3
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

// Firecode - Level 4
// Your task is to write a method - insert_range that takes in a vector of sorted,
// non-overlapping integer Intervals (aka ranges) and a new Interval - insert, and
// returns a vector of sorted Intervals where insert has been added to the vector
// in the correct spot and the required overlapping ranges have been merged.
// Target a time complexity of O(n).

// Note:
// a) [1,3] represents an interval that includes 1, 2 and 3.
// b) Intervals should be sorted based on the value of start
// c) The words Range and Interval are used interchangeably

// Examples:
// Inputs: [ [1,3], [7,10] ] & [2,6]
// Output: [ [1,6], [7,10] ]
std::vector<Interval> insert_range(std::vector<Interval> intervals_list, Interval insert) 
{
  std::vector<Interval> result;
  Interval prev;
  for (std::vector<Interval>::size_type i = 0; i < intervals_list.size(); ++i)
  {
    prev = intervals_list.at(i);
    if (prev.end < insert.start)
    {
      result.push_back(prev);
    }
    else if (prev.start > insert.end)
    {
      result.push_back(insert);
      insert = prev;
    }
    else if (prev.start <= insert.end || prev.end >= insert.start)
    {
      int newStart = std::min(prev.start, insert.start);
      int newEnd = std::max(prev.end, insert.end);
      insert = Interval(newStart, newEnd);
    }
  }
  result.push_back(insert);
  return result;
}

int main()
{
  std::vector<Interval> a = mergeIntervals(std::vector<Interval>{Interval(1,3), Interval(2,5)});
  printIntervalsList(a); // [1,5]
  
  std::vector<Interval> b = mergeIntervals(std::vector<Interval>{Interval(3,5), Interval(1,2)});
  printIntervalsList(b); // [1,2], [3,5]

  return 0;
}