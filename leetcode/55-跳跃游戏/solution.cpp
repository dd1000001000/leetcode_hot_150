class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> reachable(n, 0);
        vector<int> suffixSum(n + 1, 0);

        reachable[n - 1] = 1;
        suffixSum[n - 1] = 1;

        for (int i = n - 2; i >= 0; --i) {
            int right = min(n - 1, i + nums[i]);
            reachable[i] = suffixSum[i + 1] - suffixSum[right + 1] > 0;
            suffixSum[i] = suffixSum[i + 1] + reachable[i];
        }

        return reachable[0] == 1;
    }
};
