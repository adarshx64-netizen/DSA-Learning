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
    vector<int> rightSideView(TreeNode* root) {

        if(root == NULL) return {};

        // queue<pair<int, TreeNode*>> q;
        queue<TreeNode*> q;
        // q.push({0, root});
        q.push(root);

        vector<vector<int>> levelOrder;
        // map<int, Node*> mpp;

        while(!q.empty()) {

            // auto it = q.front();
            // int line = it.first;
            // TreeNode* node = it.second;

            // mpp[line] = node;

            // if(node->left) q.push(line - 1, node->left);
            // if(node->left) q.push(line - 1, node->left);

            vector<int> level;
            int size = q.size();

            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            levelOrder.push_back(level);
        }

        vector<int> ans;
        int n = levelOrder.size();

        for(int i = 0; i < n; i++) {
            
            int x = levelOrder[i].size();
            ans.push_back(levelOrder[i][x - 1]);
        }

        return ans;
        

        // for(auto it : mpp) {

        //     int x = it.first;
        // }
    }
};