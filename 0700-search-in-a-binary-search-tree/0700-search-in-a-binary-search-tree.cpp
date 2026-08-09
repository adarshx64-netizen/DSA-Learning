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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        // while(root) {
        //     if(val == root->val) break;

        //     if(root->val > val) root = root->left;
        //     else root = root->right;
        // }

        // return root;

        if(root == NULL || root->val == val) return root;

        if(root->val > val) return searchBST(root->left, val);
        // if(root->val < val) return searchBST(root->right, val);

        // return root;

        return searchBST(root->right, val);
    }
};