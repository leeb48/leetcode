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

// class Solution
// {
// public:
//     bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
//     {

//         vector<vector<int>> adj(numCourses);
//         vector<int> pre_req_count(numCourses, 0);

//         int count = 0;

//         for (auto &p : prerequisites)
//         {
//             cout << p[1] << endl;
//             adj[p[0]].push_back(p[1]);
//             pre_req_count[p[1]]++;
//         }

//         stack<int> stk;

//         for (int i = 0; i < pre_req_count.size(); ++i)
//         {
//             if (pre_req_count[i] == 0)
//             {
//                 stk.emplace(pre_req_count[i]);
//             }
//         }

//         while (!stk.empty())
//         {
//             count++;

//             int curr = stk.top();
//             stk.pop();

//             for (auto k : adj[curr])
//             {
//                 pre_req_count[k]--;
//                 if (pre_req_count[k] == 0)
//                 {
//                     stk.emplace(k);
//                 }
//             }
//         }

//         return count == numCourses;
//     }
// };

class Solution
{

private:
    bool dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &stk_rec, int u)
    {
        visited[u] = true;
        stk_rec[u] = true;

        for (auto iter = adj[u].begin(); iter != adj[u].end(); iter++)
        {

            int curr = *iter;

            //  True value indicates that there is a cycle
            if (stk_rec[curr] == true)
                return true;

            if (visited[curr] == false)
            {
                if (dfs(adj, visited, stk_rec, curr))
                {
                    return true;
                }
                else
                {
                    continue;
                }
            }
        }

        //  Remove the node from the current dfs path
        stk_rec[u] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        // Build the graph
        vector<vector<int>> adj(numCourses);

        for (auto &p : prerequisites)
        {
            adj[p[1]].emplace_back(p[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> stk_rec(numCourses, false);

        for (int i = 0; i < adj.size(); ++i)
        {
            if (visited[i] == false)
            {
                if (dfs(adj, visited, stk_rec, i))
                    return false;
            }
        }

        return true;
    }
};

int main()
{

    vector<vector<int>> test = {
        {0, 1},
        {2, 1},
        {3, 1}};

    Solution sol;

    sol.canFinish(3, test);
}