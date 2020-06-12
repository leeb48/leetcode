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
private:
    int CheckPal(string s, int i, int j)
    {
        int count = 0;
        while (i >= 0 && j < s.size())
        {
            if (s[i] == s[j])
                count++;
            else
                break;
            --i, ++j;
        }
        return count;
    }

public:
    int countSubstrings(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            count += CheckPal(s, i, i);
            count += CheckPal(s, i, i + 1);
        }
        return count;
    }

    int countSubstrings2(string s)
    {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                // One and two letter substrings can be calcuated directly
                dp[i][j] = s[i] == s[j] && (i - j + 1 < 3 || dp[i - 1][j + 1]);
                if (dp[i][j])
                    res++;
            }
        }
        return res;
    }
};

int main()
{
    string test1 = "aabaa";
    string test2 = "abccba";
    string test3 = "fdsklf";

    Solution sol;

    int res = sol.countSubstrings2(test3);

    return 0;
}