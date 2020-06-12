#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <deque>
#include <utility>
#include <set>
#include <list>
#include <functional>
using namespace std;

// Input: [[1,2],[2,3],[3,4],[1,3]]
// Output: 1

// Input: [[1,2],[1,2],[1,2]]
// Output: 2

// Input: [[1,2],[2,3]]
// Output: 0

// [[1,100],[11,22],[1,11],[2,12]]
// Output: 3    Expected: 2

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        if (intervals.empty())
            return 0;

        auto comp = [](const vector<int> &v1, const vector<int> &v2) {
            return v1[1] < v2[1];
        };

        sort(intervals.begin(), intervals.end(), comp);

        int count = 1;
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i)
        {

            if (intervals[i][0] >= end)
            {
                count++;
                end = intervals[i][1];
            }
        }

        return intervals.size() - count;
    }
};

int main()
{

    // [[0,2],[1,3],[2,4],[3,5],[4,6]]
    vector<vector<int>> test = {

        {0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}

    };

    Solution sol;

    int res = sol.eraseOverlapIntervals(test);

    cout << res << endl;

    return 0;
}