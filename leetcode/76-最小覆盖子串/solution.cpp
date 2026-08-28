class Solution {
public:
    string minWindow(string s, string t) {
        int need[256] = {};
        int count[256] = {};
        for (char c : t) {
            ++need[static_cast<unsigned char>(c)];
        }

        int missing = t.size();
        int p = 0;
        int bestStart = 0;
        int bestLength = INT_MAX;

        for (int i = 0; i < s.size(); ++i) {
            unsigned char current = static_cast<unsigned char>(s[i]);
            if (need[current] > 0) {
                if (count[current] < need[current]) {
                    --missing;
                }
                ++count[current];
            }

            if (missing > 0) {
                continue;
            }

            while (missing == 0) {
                unsigned char left = static_cast<unsigned char>(s[p]);
                if (need[left] > 0) {
                    --count[left];
                    if (count[left] < need[left]) {
                        ++missing;
                    }
                }
                ++p;
            }

            int length = i - p + 2;
            if (length < bestLength) {
                bestLength = length;
                bestStart = p - 1;
            }
        }

        return bestLength == INT_MAX ? "" : s.substr(bestStart, bestLength);
    }
};
