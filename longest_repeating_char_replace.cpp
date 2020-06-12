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
    int characterReplacement(string s, int k)
    {
        int l = 0, r = 0, fr = 0;
        vector<int> count(26, 0);
        int res = 0;

        while (r < s.size())
        {
            count[s[r] - 'A']++;
            res = max(res, r - l + 1);

            if ((r - l + 1) - fr > k)
            {
                count[s[l] - 'A']--;
                l++;
                fr = *(max_element(count.begin(), count.end()));
            }
            ++r;
        }
        return res;
    }
};

int main()
{
    Solution sol;

    string test1 = "ABBB";

    int res = sol.characterReplacement(test1, 2);

    return 0;
}