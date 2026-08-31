class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, set<int>> positions;
        for (int i = 0; i < nums.size(); ++i) {
            positions[nums[i]].insert(i);
        }

        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            positions[x].erase(i);
            if (positions[x].empty()) {
                positions.erase(x);
            }

            int y = target - x;
            auto it = positions.find(y);
            if (it != positions.end()) {
                return {i, *it->second.begin()};
            }
        }

        return {};
    }
};
