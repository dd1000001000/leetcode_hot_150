class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> sufmx(n);
        sufmx[n - 1] = prices[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            sufmx[i] = max(sufmx[i + 1], prices[i]);
        }

        int answer = 0;
        for (int i = 0; i < n; ++i) {
            answer = max(answer, sufmx[i] - prices[i]);
        }

        return answer;
    }
};
