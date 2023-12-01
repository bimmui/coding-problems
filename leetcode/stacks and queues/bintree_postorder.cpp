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
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        TreeNode *curr = root;
        TreeNode *prev = nullptr;
        stack<TreeNode *> st;

        while (curr != nullptr || !st.empty())
        {
            if (curr != nullptr)
            {
                st.push(curr);
                prev = curr;
                curr = curr->left;
            }

            else
            {
                TreeNode *top = st.top();
                if (top->right == nullptr || top->right == prev)
                {
                    result.push_back(top->val);
                    st.pop();
                    prev = top;
                }
                else
                {
                    curr = top->right;
                }
            }
        }
        return result;
    }
};