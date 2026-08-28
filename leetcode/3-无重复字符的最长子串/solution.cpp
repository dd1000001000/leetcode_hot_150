class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int answer = 0;

        for (int i = 0; i < n; ++i) {
            bool appeared[256] = {};
            for (int j = i; j < n && j - i < 256; ++j) {
                unsigned char character = static_cast<unsigned char>(s[j]);
                if (appeared[character]) {
                    break;
                }
                appeared[character] = true;
                answer = max(answer, j - i + 1);
            }
        }

        return answer;
    }
};
