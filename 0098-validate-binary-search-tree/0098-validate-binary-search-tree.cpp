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

    bool solve(TreeNode* node, long long minVal, long long maxVal) {

        if(node == NULL) return true;

        if(node->val <= minVal || node->val >= maxVal) return false;

        return solve(node->left, minVal, node->val) && solve(node->right, node->val, maxVal); 
    }

    bool isValidBST(TreeNode* root) {

        return solve(root, LLONG_MIN, LLONG_MAX);
        
        // if(root == NULL) return true;

        // if(root->left && root->right) {

        //     if(!(root->val > root->left->val && root->val < root->right->val)) return false;
        // }

        // else if(root->right) {

        //     if(root->val >= root->right->val) return false;
        // }

        // else if(root->left) {

        //     if(root->val <= root->left->val) return false;
        // }

        // isValidBST(root->left);
        // isValidBST(root->right);

        // return true;
    }
};