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
    int findMin(vector<int> &nums)
    {
        int lo = 0, hi = nums.size() - 1;

        while (lo < hi)
        {
            int mid = (hi - lo) / 2 + lo;

            if (nums[mid] > nums[hi])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }

        return nums[lo];
    }
};

int main()
{
}