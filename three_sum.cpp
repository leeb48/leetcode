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
#include <functional>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1, k = nums.size() - 1;

            while (j < k)
            {

                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    res.emplace_back(vector<int>{nums[i], nums[j], nums[k]});

                    ++j;

                    while (j < k && nums[j] == nums[j - 1])
                        ++j;
                }
                else if (nums[i] + nums[j] + nums[k] < 0)
                {
                    ++j;
                }
                else if (nums[i] + nums[j] + nums[k] > 0)
                {
                    --k;
                }
            }
        }

        return res;
    }
};

int main()
{
    vector<int> test{0, 0, 0};
    Solution sol;

    auto res = sol.threeSum(test);

    return 0;
}