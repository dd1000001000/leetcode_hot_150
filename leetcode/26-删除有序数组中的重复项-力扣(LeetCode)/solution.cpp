class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        // p 表示下一个不重复元素应写入的位置，也就是当前去重后的长度。
        int p = 1;
        for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
            if (nums[i] != nums[p - 1]) {
                swap(nums[p], nums[i]);
                ++p;
            }
        }

        return p;
    }
};
