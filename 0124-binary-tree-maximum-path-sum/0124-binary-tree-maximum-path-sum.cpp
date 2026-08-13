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

// maxPathThroughNode = maxGainFromLeft + node->val + maxGainFromRight
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;

        int maxSum = INT_MIN;

        dfs(root, maxSum);

        return maxSum;
    }

    int dfs(TreeNode* node, int& maxSum) {

        if(node == NULL) return 0;

        int left = max(0, dfs(node->left, maxSum));
        int right = max(0, dfs(node->right, maxSum));
    
        maxSum = max(maxSum, left + right + node->val);

        return max(left, right) + node->val;
    }
};