class Solution {
    unordered_set<int> st;

public:
    bool findTarget(TreeNode* root, int k) {
        // return BF(root, k);
        return optimal(root, k);
    }

    bool optimal(TreeNode* root, int k) {
        if(!root) return false;

        if(st.count(k - root->val)) return true;

        st.insert(root->val);

        return optimal(root->left, k) || optimal(root->right, k);
    }

    // TC -> O(n) and worst case O(n^2)
    // SC -> O(n)
    bool BF(TreeNode* root, int k) {
        unordered_set<int> s;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(s.find(k - node->val) != s.end()) return true;
                s.insert(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return false;
    }
};