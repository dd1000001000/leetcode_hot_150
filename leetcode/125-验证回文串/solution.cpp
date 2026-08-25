class Solution {
public:
    bool isPalindrome(string s) {
        string filtered_s;
        for (char c : s) {
            unsigned char character = static_cast<unsigned char>(c);
            if (isalnum(character)) {
                filtered_s += tolower(character);
            }
        }

        int l = 0;
        int r = static_cast<int>(filtered_s.size()) - 1;
        while (l < r) {
            if (filtered_s[l] != filtered_s[r]) {
                return false;
            }
            ++l;
            --r;
        }

        return true;
    }
};
