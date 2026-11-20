class Solution {
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int start, int end, int& idx) {
        if (start > end) return nullptr;

        int val = postorder[idx--];
        TreeNode* root = new TreeNode(val);

        int pos = start;
        while (inorder[pos] != val) pos++;

        root->right = build(inorder, postorder, pos + 1, end, idx);
        root->left = build(inorder, postorder, start, pos - 1, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1, idx);
    }
};