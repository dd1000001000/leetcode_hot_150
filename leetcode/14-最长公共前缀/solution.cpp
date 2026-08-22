class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLength = strs[0].size();
        for (const string& str : strs) {
            minLength = min(minLength, static_cast<int>(str.size()));
        }

        for (int i = 0; i < minLength; ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0].substr(0, minLength);
    }
};
