#include "../leetcode.h"

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(),
         [](auto &i1, auto &i2) { return i1[1] < i2[1]; });

    int current = numeric_limits<int>::min(), count = 0;
    for (auto &interval : intervals)
    {
        if (interval[0] >= current)
        {
            current = interval[1];
            ++count;
        }
    }
    return intervals.size() - count;
}

int main()
{
    vector<vector<int>> intervals;
    cin >> intervals;
    cout << eraseOverlapIntervals(intervals) << endl;
    return 0;
}
