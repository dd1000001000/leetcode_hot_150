class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mapping[256];
        fill(mapping, mapping + 256, -1);

        for (int i = 0; i < s.size(); ++i) {
            unsigned char from = static_cast<unsigned char>(s[i]);
            unsigned char to = static_cast<unsigned char>(t[i]);
            if (mapping[from] != -1) {
                if (mapping[from] != to) {
                    return false;
                }
                continue;
            }

            for (int character = 0; character < 256; ++character) {
                if (mapping[character] == to) {
                    return false;
                }
            }
            mapping[from] = to;
        }

        return true;
    }
};
