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

int LongestSubstrNoRepeat(string s)
{

    vector<int> map(128, 0);
    int l = 0, r = 0, res = 0;
    while (r < s.size())
    {

        map[s[r]]++;

        while (map[s[r]] > 1)
        {
            map[s[l]]--;
            l++;
        }

        res = max(res, r - l + 1);

        r++;
    }
    return res;
}

int main()
{
    string s = "ABBCDDEFGHHIKLMNOPQQRS";
    int res = LongestSubstrNoRepeat(s);

    return 0;
}