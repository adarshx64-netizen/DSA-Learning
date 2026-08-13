/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // BF Approach
        // return lca(root, p, q);

        // Optimal
        // TC -> O(H)
        // SC -> O()
        if(root == NULL) return root;

        // if both of them are on left then go to the left
        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        
        // if both of them are on right then go to the right
        if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);

        return root;
    }

    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL || root == p || root == q) return root;

        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);

        if(!left) return right;
        else if(!right) return left;
        return root;
    }
};