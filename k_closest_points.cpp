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

struct compare
{
    bool operator()(vector<int> &p, vector<int> &q)
    {
        return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
    }
};

vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
{
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;

    for (vector<int> &point : points)
    {
        pq.emplace(point);

        if (pq.size() > K)
            pq.pop();
    }

    vector<vector<int>> res;

    while (!pq.empty())
    {
        res.emplace_back(pq.top());

        pq.pop();
    }

    return res;
}

int main()
{
    vector<vector<int>> points{{3, 3}, {5, -1}, {-2, 4}};

    auto res = kClosest(points, 2);

    for (auto first : res)
    {
        for (auto n : first)
        {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}
