class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        int answer = INT_MAX;
        for (int i = 0; i < n; ++i) {
            long long requiredSum = prefixSum[i] + target;
            auto it = lower_bound(prefixSum.begin() + i + 1, prefixSum.end(), requiredSum);
            if (it != prefixSum.end()) {
                int end = it - prefixSum.begin();
                answer = min(answer, end - i);
            }
        }

        return answer == INT_MAX ? 0 : answer;
    }
};
