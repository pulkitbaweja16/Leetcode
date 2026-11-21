class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            Node* prev = nullptr;

            for (int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();

                if (prev) prev->next = curr;
                prev = curr;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return root;
    }
};