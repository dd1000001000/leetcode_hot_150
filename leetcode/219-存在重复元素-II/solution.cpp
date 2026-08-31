class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lst;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = lst.find(nums[i]);
            if (it != lst.end() && i - it->second <= k) {
                return true;
            }
            lst[nums[i]] = i;
        }

        return false;
    }
};
