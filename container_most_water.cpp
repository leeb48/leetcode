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
    int maxArea(vector<int> &height)
    {
        int min_height = 0, max_area = 0;

        for (int i = 0, j = height.size() - 1; i < j;)
        {
            min_height = min(height[i], height[j]);

            max_area = max(max_area, min_height * (j - i));

            while (height[i] <= min_height && i < j)
                ++i;
            while (height[j] <= min_height && i < j)
                --j;
        }
        return max_area;
    }
};

int main()
{
    vector<int> test1 = {1,
                         8,
                         6,
                         2,
                         5,
                         4,
                         8,
                         3,
                         7};
    Solution sol;

    int res = sol.maxArea(test1);

    cout << res << endl;

    return 0;
}