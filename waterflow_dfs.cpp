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
    vector<vector<int>> dir;

    void dfs(vector<vector<int>> &matrix, vector<int> &starting_point, vector<vector<bool>> &visited)
    {

        int n = matrix.size(), m = matrix[0].size();

        for (auto d : dir)
        {
            int r = starting_point[0] + d[0];
            int c = starting_point[1] + d[1];

            if (r < 0 || c < 0 || r >= n || c >= m || matrix[r][c] < matrix[starting_point[0]][starting_point[1]] || visited[r][c])
                continue;

            visited[r][c] = true;

            vector<int> next = {r, c};

            dfs(matrix, next, visited);
        }

        return;
    }

public:
    Solution()
    {
        dir = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {

        if (matrix.empty())
            return matrix;

        int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> pacific_coast, atlantic_coast;
        vector<vector<bool>> pacific(n, vector<bool>(m, false)), atlantic(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i)
        {
            pacific_coast.push_back({i, 0});
            atlantic_coast.push_back({i, m - 1});
            pacific[i][0] = true;
            atlantic[i][m - 1] = true;
        }

        for (int j = 0; j < m; ++j)
        {
            pacific_coast.push_back({0, j});
            atlantic_coast.push_back({n - 1, j});
            pacific[0][j] = true;
            atlantic[n - 1][j] = true;
        }

        for (int i = 0; i < pacific_coast.size(); ++i)
        {
            dfs(matrix, pacific_coast[i], pacific);
            dfs(matrix, atlantic_coast[i], atlantic);
        }

        vector<vector<int>> res;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
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
