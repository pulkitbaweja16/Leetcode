class Solution {
public:
    vector<string> ans;

    void solve(string s, int i, int parts, string temp) {
        if (parts == 4 && i == s.size()) {
            temp.pop_back();
            ans.push_back(temp);
            return;
        }

        if (parts == 4 || i == s.size()) return;

        for (int len = 1; len <= 3 && i + len <= s.size(); len++) {
            string x = s.substr(i, len);
            if (x.size() > 1 && x[0] == '0') break;
            if (stoi(x) > 255) break;

            solve(s, i + len, parts + 1, temp + x + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        solve(s, 0, 0, "");
        return ans;
    }
};