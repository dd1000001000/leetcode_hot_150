class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i + m <= n; ++i) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                ++j;
            }
            if (j == m) {
                return i;
            }
        }

        return -1;
    }
};
