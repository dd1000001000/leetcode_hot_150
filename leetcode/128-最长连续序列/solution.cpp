class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int answer = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            if (dp.count(nums[i] - 1)) {
                dp[nums[i]] = dp[nums[i] - 1] + 1;
            } else {
                dp[nums[i]] = 1;
            }
            answer = max(answer, dp[nums[i]]);
        }

        return answer;
    }
};
