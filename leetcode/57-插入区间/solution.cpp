class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), [](const vector<int>& first, const vector<int>& second) {
            if (first[0] != second[0]) {
                return first[0] < second[0];
            }
            return first[1] > second[1];
        });

        vector<vector<int>> answer;
        int l = intervals[0][0];
        int r = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            int x = intervals[i][0];
            int y = intervals[i][1];
            if (r < x) {
                answer.push_back({l, r});
                l = x;
                r = y;
            } else if (y > r) {
                r = y;
            }
        }
        answer.push_back({l, r});

        return answer;
    }
};