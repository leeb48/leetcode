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

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        deque<TreeNode *> stk;

        stk.emplace_back(root);

        vector<int> res;

        while (!stk.empty())
        {
            auto curr = stk.back();
            stk.pop_back();
            if (!curr)
                continue;

            res.emplace_back(curr->val);

            stk.emplace_back(curr->right);
            stk.emplace_back(curr->left);
        }

        return res;
    }
};