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
#include <deque>
#include <utility>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<int> L, R;

    L = vector<int>(nums.begin() + 2, nums.begin() + 2);

    for (int n : L)
    {
        cout << n << " ";
    }

    return 0;
}
