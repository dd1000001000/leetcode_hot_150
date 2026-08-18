class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        int r = static_cast<int>(nums.size()) - 1;

        while (l <= r) {
            // 从末尾跳过所有等于 val 的元素，r 指向可交换的非 val 元素。
            while (l <= r && nums[r] == val) {
                --r;
            }
            if (l > r) {
                break;
            }

            if (nums[l] == val) {
                swap(nums[l], nums[r]);
                --r;
            }
            ++l;
        }

        return l;
    }
};
