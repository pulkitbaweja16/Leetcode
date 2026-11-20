class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix[0].size(), ans = 0;
        vector<int> h(n, 0);

        for (auto row : matrix) {
            for (int j = 0; j < n; j++)
                h[j] = row[j] == '1' ? h[j] + 1 : 0;

            stack<int> st;
            for (int j = 0; j <= n; j++) {
                int height = j == n ? 0 : h[j];
                while (!st.empty() && h[st.top()] > height) {
                    int x = h[st.top()];
                    st.pop();
                    int width = st.empty() ? j : j - st.top() - 1;
                    ans = max(ans, x * width);
                }
                st.push(j);
            }
        }
        return ans;
    }
};