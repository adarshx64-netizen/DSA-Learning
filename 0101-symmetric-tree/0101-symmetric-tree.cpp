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
    bool isSymmetric(TreeNode* root) {
        
        vector<vector<pair<int, int>>> verticalOrder;
        verticalOrderTraversal(root, verticalOrder);

        for(int i = 0; i < verticalOrder.size(); i++) {

            int n = verticalOrder[i].size();
            for(int j = 0; j < n; j++) {

                auto it1 = verticalOrder[i][j];
                auto it2 = verticalOrder[i][n - j - 1];

                if(!(it1.first == it2.first && it1.second + it2.second == 0)) return false;

                if((n & 1) && n != 1) return false;

                // cout << it.first << " " << it.second << ", ";
            }

            // cout << endl;
        }

        
        return true;
    }

    void verticalOrderTraversal(TreeNode* root, vector<vector<pair<int, int>>>& verticalOrder) {

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()) {

            int size = q.size();
            vector<pair<int, int>> level;

            for(int i = 0; i < size; i++) {

                auto it = q.front();
                int line = it.second;
                TreeNode* node = it.first;

                if(node->left) q.push({node->left, line - 1});
                if(node->right) q.push({node->right, line + 1});

                level.push_back({node->val, line});
                q.pop();
            }

            verticalOrder.push_back(level);
        }
    }
};