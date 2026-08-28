class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ransomCount[256] = {};
        int magazineCount[256] = {};

        for (char c : ransomNote) {
            ++ransomCount[static_cast<unsigned char>(c)];
        }
        for (char c : magazine) {
            ++magazineCount[static_cast<unsigned char>(c)];
        }

        for (int i = 0; i < 256; ++i) {
            if (magazineCount[i] < ransomCount[i]) {
                return false;
            }
        }

        return true;
    }
};
