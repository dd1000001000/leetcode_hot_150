mt19937 rnd(123);
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = nums[0];
        int sum = 0;

        for (int num : nums) {
            if (num == cur) {
                ++sum;
            } else {
                --sum;
                if (sum < 0) {
                    cur = num;
                    sum = 1;
                }
            }
        }

        return cur;
    }
};
