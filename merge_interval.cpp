
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

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });

        vector<vector<int>> res;

        int i = 0, j = 1;
        while (j < intervals.size())
        {
            if (intervals[i][1] >= intervals[j][0])
            {
                intervals[i][1] = max(intervals[j][1], intervals[i][1]);
                j++;
            }
            else
            {
                res.emplace_back(intervals[i]);
                i = j;
                j = i + 1;
            }
        }
        res.emplace_back(intervals[i]);

        return res;
    }
};

int main()
{
    vector<vector<int>> ex1{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ex2{{1, 4}, {4, 5}};

    Solution sol;
    auto answer = sol.merge(ex2);

    for (auto &v : answer)
    {
        cout << "[ ";
        for (int n : v)
        {
            cout << n << " ";
        }
        cout << " ]" << endl;
    }

    return 0;
}