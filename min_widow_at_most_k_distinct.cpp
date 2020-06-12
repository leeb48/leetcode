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

int MinWindowAtMostKDistinct(string s, int k)
{
    vector<int> map(256, 0);
    int l = 0, r = 0, unique = 0;
    int res = 0;
    while (r < s.size())
    {
        if (map[s[r]] == 0)
            unique++;
        map[s[r]]++;
        r++;

        while (unique > k)
        {
            if (map[s[l]] == 1)
                unique--;
            map[s[l]]--;
            l++;
        }
        res = max(res, r - l);
    }
    return res;
}

int main()
{
    string t = "AAAAAAAA";

    int res = MinWindowAtMostKDistinct(t, 3);

    return 0;
}