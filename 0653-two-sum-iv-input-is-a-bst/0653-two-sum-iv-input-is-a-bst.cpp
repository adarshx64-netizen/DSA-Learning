class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        multiset<int> st;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(st.find(k - node->val) != st.end()) return true;
                st.insert(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return false;
    }
};