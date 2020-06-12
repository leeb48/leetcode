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

// 733. Flood Fill

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    // Look up
    if (sr > 0 && image[sr - 1][sc] == image[sr][sc])
    {
        floodFill(image, sr - 1, sc, newColor);
    }

    // Look right
    if (sc < image[0].size() - 1 && image[sr][sc + 1] == image[sr][sc])
    {
        floodFill(image, sr, sc + 1, newColor);
    }

    // Look down
    if (sr < image.size() - 1 && image[sr + 1][sc] == image[sr][sc])
    {
        floodFill(image, sr + 1, sc, newColor);
    }

    // Look left
    if (sc > 0 && image[sr][sc - 1] == image[sr][sc])
    {
        floodFill(image, sr, sc - 1, newColor);
    }

    image[sr][sc] = newColor;

    return image;
}

int main()
{

    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    int sr = 1, sc = 1, newColor = 2;

    // floodFill(image, sr, sc, newColor);

    return 0;
}
