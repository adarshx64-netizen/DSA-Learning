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
class Solution {
public:

    vector<int> preOrder(TreeNode* root) {

        vector<int> res;

        if(!root) return res;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {

            TreeNode* node = st.top();
            st.pop();

            // Push the current node value in result
            res.push_back(node->val);

            // If right exist then go to the right, instead of left (think why ??)
            if(node->right) st.push(node->right);
            // If left exist then go to the left
            if(node->left) st.push(node->left);
        }

        return res;
    }

    void preorder(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return;

        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        return preOrder(root);  // Using Stack
    }
};