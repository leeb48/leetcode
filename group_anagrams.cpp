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
    string strSort(string str)
    {

        int count[26] = {0};
        for (char c : str)
        {
            count[c - 'a']++;
        }

        string t;

        for (int c = 0; c < 26; ++c)
        {
            t += string(count[c], c + 'a');
        }
        return t;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;

        for (string s : strs)
        {
            mp[strSort(s)].emplace_back(s);
        }

        vector<vector<string>> res;

        for (auto p : mp)
        {
            res.emplace_back(p.second);
        }
        return res;
    }
};

int main()
{
    vector<string> strs = {"bat", "hat", "eat", "ate", "num", "tea", "eat", "tan", "nat"};

    Solution sol;

    auto answer = sol.groupAnagrams(strs);

    for (auto &v : answer)
    {
        cout << "[ ";
        for (string s : v)
        {
            cout << s << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}