class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> answer;
        int n = words.size();

        for (int start = 0; start < n;) {
            int end = start;
            int wordLengthSum = 0;
            while (end < n && wordLengthSum + words[end].size() + (end - start) <= maxWidth) {
                wordLengthSum += words[end].size();
                ++end;
            }

            int wordCount = end - start;
            string line;
            if (end == n || wordCount == 1) {
                for (int i = start; i < end; ++i) {
                    if (i > start) {
                        line += ' ';
                    }
                    line += words[i];
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                int spaceCount = maxWidth - wordLengthSum;
                int gapCount = wordCount - 1;
                int spacesPerGap = spaceCount / gapCount;
                int extraSpaces = spaceCount % gapCount;

                for (int i = start; i < end; ++i) {
                    line += words[i];
                    if (i < end - 1) {
                        int spaces = spacesPerGap + (i - start < extraSpaces ? 1 : 0);
                        line += string(spaces, ' ');
                    }
                }
            }

            answer.push_back(line);
            start = end;
        }

        return answer;
    }
};
