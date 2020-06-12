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
    string minWindow(string s, string t)
    {
        int l = 0, r = 0, min_start = 0, min_length = -1, count = t.size();
        vector<int> map(128, 0);
        for (auto c : t)
        {
            map[c]++;
        }

        while (r < s.size())
        {
            if (map[s[r]] > 0)
            {
                count--;
            }
            map[s[r]]--;
            r++;

            while (count == 0)
            {
                if (min_length == -1 || min_length > r - l)
                {
                    min_length = r - l;
                    min_start = l;
                }

                map[s[l]]++;
                if (map[s[l]] > 0)
                {
                    count++;
                }
                l++;
            }
        }
        return min_length == -1 ? "" : s.substr(min_start, min_length);
    }
};

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution sol;

    string res = sol.minWindow(s, t);

    return 0;
}