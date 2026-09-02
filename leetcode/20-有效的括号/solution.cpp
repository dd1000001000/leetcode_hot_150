class Solution {
public:
    bool isValid(string s) {
        stack<char> leftBrackets;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                leftBrackets.push(c);
                continue;
            }

            if (leftBrackets.empty()) {
                return false;
            }
            char left = leftBrackets.top();
            leftBrackets.pop();
            if ((c == ')' && left != '(') || (c == ']' && left != '[')
                || (c == '}' && left != '{')) {
                return false;
            }
        }

        return leftBrackets.empty();
    }
};
