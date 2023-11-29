/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Used https://en.wikipedia.org/wiki/Binary_search_tree#Traversal for reference
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> order;

        if (root == nullptr)
        {
            return order;
        }

        // Traversing left node first
        vector<int> left_contents = inorderTraversal(root->left);
        order.insert(order.end(), left_contents.begin(), left_contents.end());

        // Getting the contents of the curr node (middle)
        order.push_back(root->val);

        // Traversing right node last
        vector<int> right_contents = inorderTraversal(root->right);
        order.insert(order.end(), right_contents.begin(), right_contents.end());

        return order;
    }
};