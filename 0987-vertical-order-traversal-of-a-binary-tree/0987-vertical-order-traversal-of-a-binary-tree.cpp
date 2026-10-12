class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {{}};
        return solve(root);
    }

    vector<vector<int>> solve(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        map<int, map<int, multiset<int>>> mpp;

        // bfs
        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int line = it.second.first;
            int lvl = it.second.second;

            mpp[line][lvl].insert(node->val);

            if(node->left) q.push({node->left, {line - 1, lvl + 1}});
            if(node->right) q.push({node->right, {line + 1, lvl + 1}});
        }

        vector<vector<int>> res;
        for(auto it : mpp) {
            vector<int> col;

            // Traverse each level of the current vertical line
            for(auto x : it.second) { 
                // // x.first  = level
                // // x.second = multiset of node values
                // for(auto y : x.second) {
                //     col.push_back(y);
                // }
                
                // or
                col.insert(col.end(), x.second.begin(), x.second.end());
            }

            res.push_back(col);
        }

        return res;
    }
};