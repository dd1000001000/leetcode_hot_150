class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const unsigned long long base1 = 131;
        const unsigned long long base2 = 233;
        int n = s.size();
        int wordLength = words[0].size();
        int wordCount = words.size();
        int windowLength = wordLength * wordCount;
        if (windowLength > n) {
            return {};
        }

        vector<unsigned long long> power1(n + 1, 1), power2(n + 1, 1);
        vector<unsigned long long> prefixHash1(n + 1), prefixHash2(n + 1);
        for (int i = 0; i < n; ++i) {
            power1[i + 1] = power1[i] * base1;
            power2[i + 1] = power2[i] * base2;
            prefixHash1[i + 1] = prefixHash1[i] * base1 + static_cast<unsigned char>(s[i]);
            prefixHash2[i + 1] = prefixHash2[i] * base2 + static_cast<unsigned char>(s[i]);
        }

        auto getHash = [&](int left, int right) {
            return pair<unsigned long long, unsigned long long>{
                prefixHash1[right] - prefixHash1[left] * power1[right - left],
                prefixHash2[right] - prefixHash2[left] * power2[right - left]
            };
        };
        auto hashString = [&](const string& word) {
            unsigned long long hash1 = 0;
            unsigned long long hash2 = 0;
            for (char c : word) {
                hash1 = hash1 * base1 + static_cast<unsigned char>(c);
                hash2 = hash2 * base2 + static_cast<unsigned char>(c);
            }
            return pair<unsigned long long, unsigned long long>{hash1, hash2};
        };

        unsigned long long wordsXorHash1 = 0;
        unsigned long long wordsXorHash2 = 0;
        unordered_map<string, int> needed;
        for (const string& word : words) {
            auto hash = hashString(word);
            wordsXorHash1 ^= hash.first;
            wordsXorHash2 ^= hash.second;
            ++needed[word];
        }

        vector<unsigned long long> blockXorPrefix1(n + 1), blockXorPrefix2(n + 1);
        for (int offset = 0; offset < wordLength; ++offset) {
            for (int end = offset + wordLength; end <= n; end += wordLength) {
                auto hash = getHash(end - wordLength, end);
                blockXorPrefix1[end] = blockXorPrefix1[end - wordLength] ^ hash.first;
                blockXorPrefix2[end] = blockXorPrefix2[end - wordLength] ^ hash.second;
            }
        }

        vector<int> answer;
        for (int start = 0; start + windowLength <= n; ++start) {
            unsigned long long currentXorHash1 = blockXorPrefix1[start + windowLength]
                ^ blockXorPrefix1[start];
            unsigned long long currentXorHash2 = blockXorPrefix2[start + windowLength]
                ^ blockXorPrefix2[start];
            if (currentXorHash1 != wordsXorHash1 || currentXorHash2 != wordsXorHash2) {
                continue;
            }

            unordered_map<string, int> found;
            bool valid = true;
            for (int k = 0; k < wordCount; ++k) {
                string word = s.substr(start + k * wordLength, wordLength);
                auto it = needed.find(word);
                if (it == needed.end() || ++found[word] > it->second) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                answer.push_back(start);
            }
        }

        return answer;
    }
};
