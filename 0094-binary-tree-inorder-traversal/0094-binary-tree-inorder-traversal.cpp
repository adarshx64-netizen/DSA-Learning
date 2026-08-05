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
    void inorder(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> inOrder(TreeNode* root) {
        vector<int> ans;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            int size = st.size();

            for(int i = 0; i < size; i++) {
                TreeNode* node = st.top();
                st.pop();

                if(node->left != NULL) st.push(node->left);
                if(node->right != NULL) st.push(node->right);

                ans.push_back(node->val);
            }
        }

        return ans;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};