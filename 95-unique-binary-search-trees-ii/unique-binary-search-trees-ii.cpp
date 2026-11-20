class Solution {
public:
    vector<TreeNode*> build(int l, int r) {
        if (l > r) return {nullptr};

        vector<TreeNode*> ans;
        for (int i = l; i <= r; i++) {
            auto left = build(l, i - 1);
            auto right = build(i + 1, r);

            for (auto a : left) {
                for (auto b : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = a;
                    root->right = b;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }
};