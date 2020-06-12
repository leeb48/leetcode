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
    vector<int> postorderTraversal(TreeNode *root)
    {

        // unordered_set<TreeNode *> set;
        // vector<int> res;
        // vector<TreeNode *> stk;

        // while (root || !stk.empty())
        // {

        //     // Add all the unseen nodes in the left subtree
        //     while (root && !set.count(root))
        //     {
        //         stk.emplace_back(root);
        //         root = root->left;
        //     }

        //     root = stk.back();

        //     if (root->right && !set.count(root->right))
        //     {
        //         root = root->right;
        //         continue;
        //     }

        //     stk.pop_back();
        //     res.emplace_back(root->val);
        //     set.emplace(root);
        //     root = set.count(root->right) ? nullptr : root->right;
        // }

        // return res;

        vector<TreeNode *> stk;
        TreeNode *last_added = nullptr;
        vector<int> res;

        while (root || !stk.empty())
        {

            // Add the nodes along the left subtree
            if (root && root != last_added)
            {
                stk.emplace_back(root);
                root = root->left;
            }
            else
            {
                auto currNode = stk.back();
                // Check the right subtree first
                if (currNode->right && currNode->right != nullptr)
                {
                    root = currNode->right;
                }
                // Finally add the parent node
                else
                {
                    res.emplace_back(currNode->val);
                    stk.pop_back();
                    last_added = currNode;
                }
            }
        }

        return res;
    }
};

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);

    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(5);

    root->right = new TreeNode(6);
    root->right->left = new TreeNode(7);

    Solution sol;

    auto res = sol.postorderTraversal(root);

    return 0;
}