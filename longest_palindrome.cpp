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
    int longestPalindrome(string s)
    {
        unordered_set<char> seen;
        int res = 0;

        for (char c : s)
        {
            if (seen.count(c))
            {
                res += 2;
                seen.erase(c);
            }
            else
            {
                seen.emplace(c);
            }
        }
        return seen.empty() ? res : res + 1;
    }
};

int main()
{
}