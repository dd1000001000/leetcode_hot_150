class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        const int INF = n + 1;
        vector<int> dp(n, INF);

        int treeSize = 1;
        while (treeSize < n) {
            treeSize <<= 1;
        }
        vector<int> rangeMin(treeSize * 2, INF);

        dp[n - 1] = 0;
        rangeMin[treeSize + n - 1] = 0;
        for (int node = (treeSize + n - 1) / 2; node > 0; node /= 2) {
            rangeMin[node] = min(rangeMin[node * 2], rangeMin[node * 2 + 1]);
        }

        for (int i = n - 2; i >= 0; --i) {
            int right = min(n - 1, i + nums[i]);
            if (right > i) {
                int leftNode = treeSize + i + 1;
                int rightNode = treeSize + right;
                int best = INF;

                while (leftNode <= rightNode) {
                    if (leftNode % 2 == 1) {
                        best = min(best, rangeMin[leftNode++]);
                    }
                    if (rightNode % 2 == 0) {
                        best = min(best, rangeMin[rightNode--]);
                    }
                    leftNode /= 2;
                    rightNode /= 2;
                }
                dp[i] = best + 1;
            }

            int node = treeSize + i;
            rangeMin[node] = dp[i];
            for (node /= 2; node > 0; node /= 2) {
                rangeMin[node] = min(rangeMin[node * 2], rangeMin[node * 2 + 1]);
            }
        }

        return dp[0];
    }
};
