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
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        int even = 0, odd = 1;

        while (even < A.size())
        {

            if (A[even] % 2 != 0)
            {
                while (A[odd] % 2 != 0 && odd < A.size())
                    odd += 2;
                swap(A[even], A[odd]);
                even += 2;
            }
            else
            {
                even += 2;
            }
        }
        return A;
    }
};

int main()
{
    vector<int> test1{4, 2, 5, 7, 12, 11, 13, 15, 17, 20, 22, 26};

    Solution sol;
    auto res = sol.sortArrayByParityII(test1);

    return 0;
}