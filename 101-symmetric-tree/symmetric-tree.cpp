class Solution {
public:
    bool check(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;

        return a->val == b->val &&
               check(a->left, b->right) &&
               check(a->right, b->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};