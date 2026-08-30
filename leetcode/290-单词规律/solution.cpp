class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream stream(s);
        while (stream >> word) {
            words.push_back(word);
        }
        if (words.size() != pattern.size()) {
            return false;
        }

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        for (int i = 0; i < pattern.size(); ++i) {
            char character = pattern[i];
            const string& currentWord = words[i];

            if (charToWord.count(character) && charToWord[character] != currentWord) {
                return false;
            }
            if (wordToChar.count(currentWord) && wordToChar[currentWord] != character) {
                return false;
            }

            charToWord[character] = currentWord;
            wordToChar[currentWord] = character;
        }

        return true;
    }
};