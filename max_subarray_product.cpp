
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
    int maxProduct(vector<int> &nums)
    {
        int prev_max;
        int prev_min;
        int res;

        prev_max = prev_min = res = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {

            if (nums[i] < 0)
            {
                swap(prev_max, prev_min);
            }

            prev_max = max(nums[i], nums[i] * prev_max);
            prev_min = min(nums[i], nums[i] * prev_min);

            if (res < prev_max)
            {
                res = prev_max;
            }
        }

        return res;
    }
};

int main()
{
}