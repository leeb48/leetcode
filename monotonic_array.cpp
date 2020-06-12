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
    bool isMonotonic(vector<int> &A)
    {
        bool inc, dec;
        inc = dec = true;

        for (int i = 1; i < A.size(); ++i)
        {
            inc &= A[i - 1] <= A[i];
            dec &= A[i - 1] >= A[i];
        }

        return inc || dec;
    }
};

int main()
{

    return 0;
}