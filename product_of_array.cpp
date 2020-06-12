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
#include <functional>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> res(nums.size());
        res[0] = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int r_product = nums.back();

        for (int j = nums.size() - 2; j >= 0; --j)
        {
            res[j] = res[j] * r_product;
            r_product *= nums[j];
        }

        return res;
    }
};

int main()
{

    Solution sol;

    return 0;
}