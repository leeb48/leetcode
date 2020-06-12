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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode *p, TreeNode *q)
{
    queue<TreeNode *> Q1, Q2;
    Q1.emplace(p), Q2.emplace(q);

    while (!Q1.empty() && !Q2.empty())
    {
        TreeNode *n1, *n2;
        n1 = Q1.front(), n2 = Q2.front();

        if (!n1 && !n2)
        {
            Q1.pop(), Q2.pop();
        }
        else if (!n1 || !n2)
        {
            return false;
        }

        if (n1->val != n2->val)
            return false;

        Q1.emplace(n1->left), Q1.emplace(n1->right);
        Q2.emplace(n2->left), Q2.emplace(n2->right);
    }

    if (!Q1.empty() || !Q2.empty())
        return false;

    return true;
}

int main()
{

    return 0;
}