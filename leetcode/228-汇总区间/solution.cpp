class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;
        if (nums.empty()) {
            return answer;
        }

        auto addRange = [&](int start, int end) {
            if (start == end) {
                answer.push_back(to_string(start));
            } else {
                answer.push_back(to_string(start) + "->" + to_string(end));
            }
        };

        int lst = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (static_cast<long long>(nums[i]) - nums[i - 1] > 1) {
                addRange(lst, nums[i - 1]);
                lst = nums[i];
            }
        }
        addRange(lst, nums.back());

        return answer;
    }
};
