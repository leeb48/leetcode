#include <iostream>
#include <string>
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
    void bfs(vector<vector<int>> matrix, queue<vector<int>> &q, vector<vector<bool>> &visited)
    {
        while (!q.empty())
        {
            int n = matrix.size(), m = matrix[0].size();

            vector<int> curr = q.front();
            q.pop();

            for (auto d : dir)
            {
                int r = curr[0] + d[0];
                int c = curr[1] + d[1];

                if (r < 0 || c < 0 || r >= n || c >= m || matrix[r][c] < matrix[curr[0]][curr[1]] || visited[r][c])
                    continue;

                q.emplace(vector<int>{r, c});
                visited[r][c] = true;
            }
        }
    }

    vector<vector<int>> dir;

public:
    Solution()
    {
        dir = {{-1, 0},
               {0, 1},
               {1, 0},
               {0, -1}};
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return matrix;

        int n = matrix.size(), m = matrix[0].size();

        // Create a queue to store the side of the matrix
        queue<vector<int>> pacific_q, atlantic_q;
        vector<vector<bool>> pacific(n, vector<bool>(m, false)), atlantic(n, vector<bool>(m, false));

        vector<vector<int>> res;

        // Add horizontal
        for (int i = 0; i < n; ++i)
        {
            pacific_q.emplace(vector<int>{i, 0});
            atlantic_q.emplace(vector<int>{i, m - 1});
            pacific[i][0] = true;
            atlantic[i][m - 1] = true;
        }

        for (int j = 0; j < m; ++j)
        {
            pacific_q.emplace(vector<int>{0, j});
            atlantic_q.emplace(vector<int>{n - 1, j});
            pacific[0][j] = true;
            atlantic[n - 1][j] = true;
        }

        bfs(matrix, pacific_q, pacific);
        bfs(matrix, atlantic_q, atlantic);

        for (int x = 0; x < n; ++x)
        {
            for (int y = 0; y < m; ++y)
            {
                if (pacific[x][y] && atlantic[x][y])
                    res.push_back({x, y});
            }
        }

        return res;
    }
};

int main()
{

    vector<vector<int>> test1 = {
        {1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};

    Solution sol;

    auto res = sol.pacificAtlantic(test1);

    return 0;
}