class Solution {
public:
    int romanToInt(string s) {
        auto value = [](char c) {
            switch (c) {
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                default: return 1000;
            }
        };

        int answer = 0;
        for (int i = 0; i < s.size(); ++i) {
            int current = value(s[i]);
            if (i + 1 < s.size() && current < value(s[i + 1])) {
                answer -= current;
            } else {
                answer += current;
            }
        }

        return answer;
    }
};