class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i + 1 < n; ++i) {
            if (ratings[i] < ratings[i + 1]) {
                graph[i].push_back(i + 1);
                ++indegree[i + 1];
            } else if (ratings[i] > ratings[i + 1]) {
                graph[i + 1].push_back(i);
                ++indegree[i];
            }
        }

        queue<int> nodes;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                nodes.push(i);
            }
        }

        while (!nodes.empty()) {
            int current = nodes.front();
            nodes.pop();

            for (int next : graph[current]) {
                dp[next] = max(dp[next], dp[current] + 1);
                if (--indegree[next] == 0) {
                    nodes.push(next);
                }
            }
        }

        int answer = 0;
        for (int candies : dp) {
            answer += candies;
        }
        return answer;
    }
};
