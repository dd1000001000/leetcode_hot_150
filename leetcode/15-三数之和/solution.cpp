class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int write = 0;
        for (int read = 0; read < nums.size(); ++read) {
            if (write < 3 || nums[read] != nums[write - 3]) {
                nums[write] = nums[read];
                ++write;
            }
        }
        nums.resize(write);

        int n = nums.size();
        vector<vector<int>> answer;

        for (int i = 0; i < n; ++i) {
            int l = 0;
            int r = n - 1;

            while (l < r) {
                if (l == i) {
                    ++l;
                    continue;
                }
                if (r == i) {
                    --r;
                    continue;
                }

                int sum = nums[l] + nums[r];
                if (sum < -nums[i]) {
                    ++l;
                } else if (sum > -nums[i]) {
                    --r;
                } else {
                    answer.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                }
            }
        }

        for (vector<int>& triplet : answer) {
            sort(triplet.begin(), triplet.end());
        }
        sort(answer.begin(), answer.end());
        answer.erase(unique(answer.begin(), answer.end()), answer.end());

        return answer;
    }
};
