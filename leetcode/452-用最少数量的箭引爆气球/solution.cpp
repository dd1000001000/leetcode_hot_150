class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        set<pair<int, int>> s1;
        set<pair<int, int>> s2;
        for (const vector<int>& point : points) {
            s1.insert({point[0], point[1]});
            s2.insert({point[1], point[0]});
        }

        int answer = 0;
        while (!s2.empty()) {
            int r = s2.begin()->first;
            ++answer;

            while (!s1.empty() && s1.begin()->first <= r) {
                auto interval = s1.begin();
                int l = interval->first;
                int right = interval->second;
                s2.erase({right, l});
                s1.erase(interval);
            }
        }

        return answer;
    }
};
