class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        vector<int> prefixMax(n), suffixMax(n);
        prefixMax[0] = height[0];
        suffixMax[n - 1] = height[n - 1];

        for (int i = 1; i < n; ++i) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }

        vector<int> levels = height;
        sort(levels.begin(), levels.end());
        levels.erase(unique(levels.begin(), levels.end()), levels.end());

        int answer = 0;
        for (int h : levels) {
            int i = lower_bound(prefixMax.begin(), prefixMax.end(), h) - prefixMax.begin();

            int left = 0;
            int right = n - 1;
            int j = 0;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (suffixMax[mid] >= h) {
                    j = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            answer = max(answer, h * (j - i));
        }

        return answer;
    }
};
