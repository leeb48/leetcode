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
    void eraseIsland(vector<vector<char>> &grid, int x, int y)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (x < 0 || x == m || y < 0 || y == n || grid[x][y] == '0')
            return;

        grid[x][y] = '0';
        eraseIsland(grid, x, y + 1);
        eraseIsland(grid, x + 1, y);
        eraseIsland(grid, x, y - 1);
        eraseIsland(grid, x - 1, y);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    eraseIsland(grid, i, j);
                }
            }
        }
        return res;
    }
};

class Solution2
{
public:
    int numIslands(vector<vector<char>> &grid)
    {

        if (grid.empty())
            return 0;

        int m = grid.size(), n = grid[0].size();
        int res = 0;
        int offset[] = {-1, 0, 1, 0, -1}; // up right down left

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {

                if (grid[i][j] == '1')
                {
                    res++;
                    queue<pair<int, int>> q;
                    q.emplace(make_pair(i, j));
                    grid[i][j] = '0';

                    while (!q.empty())
                    {
                        pair<int, int> curr = q.front();
                        q.pop();
                        for (int k = 0; k < 4; ++k)
                        {
                            int r = curr.first + offset[k];
                            int c = curr.second + offset[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1')
                            {
                                grid[r][c] = '0';
                                q.emplace(make_pair(r, c));
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
}