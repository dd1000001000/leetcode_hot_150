class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
        unsigned int letterHash[26];
        for (unsigned int& hash : letterHash) {
            hash = generator();
        }

        unordered_map<unsigned int, vector<string>> groups;
        for (const string& str : strs) {
            unsigned int hash = 0;
            for (char c : str) {
                hash += letterHash[c - 'a'];
            }
            groups[hash].push_back(str);
        }

        vector<vector<string>> answer;
        for (auto& [hash, group] : groups) {
            answer.push_back(group);
        }
        return answer;
    }
};