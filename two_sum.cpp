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

vector<int> twoSum(vector<int> &nums, int target)
{
    int first = 0, second = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (mp.count(nums[i]))
        {
            first = mp[nums[i]];
            second = i;
            break;
        }

        mp[target - nums[i]] = i;
    }
    return {first, second};
}

int main()
{
    vector<int> nums{3, 2, 4};
    int target = 6;

    vector<int> res;
    res = twoSum(nums, target);

    for (int n : res)
    {
        cout << n << " ";
    }

    return 0;
}