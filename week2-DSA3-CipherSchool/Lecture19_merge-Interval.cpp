#include <bits/stdc++.h>
using namespace std;
bool comparator(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first < b.first)
        return true;
    else if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
    {
        return false;
    }
}
bool areOverlapping(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second >= b.first;
}

pair<int, int> mergeOverlappingIntervals(const pair<int, int> &a, const pair<int, int> &b)
{
    return {a.first, max(a.second, b.second)};
}

vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> &intervals)
{
    if (intervals.size() <= 1)
    {
        return intervals;
    }
    vector<pair<int, int>> result;
    sort(intervals.begin(), intervals.end(), comparator);
    result.push_back(intervals[0]);
    for (int 1 = 1; أ < intervals.size(); i++)
    {
        if (areOverlapping(result.back(), intervals[i]))
        {
            pair<int, int> overlapped = mergeOverlappingIntervals(result.back(), intervals[i]);
            result.pop_back();
            result.push_back(overlapped);
        }
        else
        {
            result.push_back(intervals[i]);
        }
    }
    return result;
}

int main()
{
}
