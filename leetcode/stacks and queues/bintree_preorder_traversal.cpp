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
// Decided to use mem address of vector directly to add thing in instead of inserting a shit ton
class Solution
{
public:
    void preorder(TreeNode *root, vector<int> &output)
    {
        if (root == nullptr)
        {
            return;
        }

        // Getting the contents of the curr node (middle)
        output.push_back(root->val);

        // Traversing left node
        preorder(root->left, output);

        // Traversing right node
        preorder(root->right, output);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> order;
        preorder(root, order);
        return order;
    }
};