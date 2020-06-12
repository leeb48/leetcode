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
private:
    struct NodeItem
    {
        TreeNode *node;
        long upper, lower;
    };

    bool
    help(TreeNode *node, int upper = INT32_MAX, int lower = INT32_MIN)
    {

        if (!node)
            return true;

        int val = node->val;

        if (val >= upper || val <= lower)
            return false;

        if (!help(node->left, val, lower))
            return false;

        if (!help(node->right, upper, val))
            return false;

        return true;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        deque<TreeNode *> stk;
        long prev_num = INT64_MIN;

        while (root || !stk.empty())
        {
            while (root)
            {
                stk.emplace_front(root);
                root = root->left;
            }
            auto curr = stk.front();
            stk.pop_front();

            if (prev_num >= curr->val)
                return false;
            prev_num = curr->val;
            root = curr->right;
        }

        return true;
    }
};

int main()
{

    return 0;
}