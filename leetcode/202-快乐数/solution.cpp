class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> visited;
        while (n != 1) {
            if (visited.count(n)) {
                return false;
            }
            visited[n] = true;

            int next = 0;
            while (n > 0) {
                int digit = n % 10;
                next += digit * digit;
                n /= 10;
            }
            n = next;
        }

        return true;
    }
};
