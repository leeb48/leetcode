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
#include <functional>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {

        if (s.empty())
            return true;

        unordered_map<char, char> closings{
            {')', '('}, {']', '['}, {'}', '{'}};

        string openings;

        for (char c : s)
        {

            // If it is an opening, add it to the openings string
            if (!closings.count(c))
            {
                openings.push_back(c);
                continue;
            }

            // If it is a closing, match it with the last seen opening
            if (openings.back() == closings[c])
            {
                // It is a match
                openings.pop_back();
            }
            else
            {
                return false;
            }
        }

        return openings.empty() ? true : false;
    }
};

int main()
{
    Solution sol;

    string s = "(({[()]))";

    cout << sol.isValid(s) << endl;

    return 0;
}
