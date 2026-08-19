class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size();
        k %= n;

        int ringCount = gcd(n, k);
        for (int start = 0; start < ringCount; ++start) {
            int current = start;
            int carried = nums[current];

            do {
                int next = (current + k) % n;
                swap(carried, nums[next]);
                current = next;
            } while (current != start);
        }
    }

private:
    int gcd(int a, int b) {
        while (b != 0) {
            int remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }
};
