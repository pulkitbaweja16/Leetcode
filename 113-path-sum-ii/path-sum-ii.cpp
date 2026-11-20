class Solution {
public:
    vector<vector<int>> ans;

    void solve(TreeNode* root, int target, vector<int>& path) {
        if (!root) return;

        path.push_back(root->val);

        if (!root->left && !root->right && target == root->val)
            ans.push_back(path);

        solve(root->left, target - root->val, path);
        solve(root->right, target - root->val, path);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        solve(root, targetSum, path);
        return ans;
    }
};