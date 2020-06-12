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

// DP solution
// class Solution
// {

// public:
//     string longestPalindrome(string s)
//     {
//         vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
//         int start = 0, end = 0;
//         for (int i = 0; i < s.size(); ++i)
//         {
//             for (int j = i; j >= 0; --j)
//             {
//                 dp[i][j] = (s[i] == s[j]) && (i - j + 1 < 3 || dp[i - 1][j + 1]);

//                 if (dp[i][j] && end - start + 1 < i - j + 1)
//                 {
//                     start = j, end = i;
//                 }
//             }
//         }
//         return s.substr(start, end - start + 1);
//     }

// };

class Solution
{

public:
    string longestPalindrome(string s)
    {
        int len = s.size(), pal_start = 0, max_len = 0, l = 0, r = 0;
        for (int start = 0; start < len && len - start > max_len / 2;)
        {
            l = r = start;
            while (r < len - 1 && s[r] == s[r + 1])
            {
                r++;
            }
            start = r + 1;
            while (l > 0 && r < len - 1 && s[l - 1] == s[r + 1])
            {
                l--, r++;
            }
            if (max_len < r - l + 1)
            {
                max_len = r - l + 1;
                pal_start = l;
            }
        }

        return s.substr(pal_start, max_len);
    }
};

int main()
{
    string s = "baaaaaa";

    Solution sol;

    string ans = sol.longestPalindrome(s);

    return 0;
}