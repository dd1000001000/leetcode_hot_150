class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p = 0;
        int n = s.size();

        for (char c : t) {
            if (p < n && c == s[p]) {
                ++p;
            }
        }

        return p == n;
    }
};
