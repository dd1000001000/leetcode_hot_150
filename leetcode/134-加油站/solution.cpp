class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<long long> pre(n);
        for (int i = 0; i < n; ++i) {
            long long gain = gas[i] - cost[i];
            pre[i] = gain + (i == 0 ? 0 : pre[i - 1]);
        }

        SegmentTree tree(pre);
        long long mnpre = 0;

        for (int start = 0; start < n; ++start) {
            if (start > 0) {
                long long movedGain = gas[start - 1] - cost[start - 1];
                tree.rangeAdd(start, n - 1, -movedGain);
                mnpre = min(mnpre, pre[start - 1]);
            }

            long long remainingMin = tree.rangeMin(start, n - 1);
            long long fuelAfterFirstPart = tree.rangeMin(n - 1, n - 1);
            if (remainingMin >= 0 && fuelAfterFirstPart >= -mnpre) {
                return start;
            }
        }

        return -1;
    }

private:
    class SegmentTree {
    public:
        SegmentTree(const vector<long long>& values) : n(values.size()), minimum(n * 4), lazy(n * 4) {
            build(1, 0, n - 1, values);
        }

        void rangeAdd(int left, int right, long long delta) {
            add(1, 0, n - 1, left, right, delta);
        }

        long long rangeMin(int left, int right) {
            return query(1, 0, n - 1, left, right);
        }

    private:
        int n;
        vector<long long> minimum;
        vector<long long> lazy;

        void build(int node, int left, int right, const vector<long long>& values) {
            if (left == right) {
                minimum[node] = values[left];
                return;
            }

            int middle = left + (right - left) / 2;
            build(node * 2, left, middle, values);
            build(node * 2 + 1, middle + 1, right, values);
            minimum[node] = min(minimum[node * 2], minimum[node * 2 + 1]);
        }

        void apply(int node, long long delta) {
            minimum[node] += delta;
            lazy[node] += delta;
        }

        void pushDown(int node) {
            if (lazy[node] == 0) {
                return;
            }
            apply(node * 2, lazy[node]);
            apply(node * 2 + 1, lazy[node]);
            lazy[node] = 0;
        }

        void add(int node, int left, int right, int updateLeft, int updateRight, long long delta) {
            if (updateLeft <= left && right <= updateRight) {
                apply(node, delta);
                return;
            }

            pushDown(node);
            int middle = left + (right - left) / 2;
            if (updateLeft <= middle) {
                add(node * 2, left, middle, updateLeft, updateRight, delta);
            }
            if (updateRight > middle) {
                add(node * 2 + 1, middle + 1, right, updateLeft, updateRight, delta);
            }
            minimum[node] = min(minimum[node * 2], minimum[node * 2 + 1]);
        }

        long long query(int node, int left, int right, int queryLeft, int queryRight) {
            if (queryLeft <= left && right <= queryRight) {
                return minimum[node];
            }

            pushDown(node);
            int middle = left + (right - left) / 2;
            long long answer = 1LL << 60;
            if (queryLeft <= middle) {
                answer = min(answer, query(node * 2, left, middle, queryLeft, queryRight));
            }
            if (queryRight > middle) {
                answer = min(answer, query(node * 2 + 1, middle + 1, right, queryLeft, queryRight));
            }
            return answer;
        }
    };
};
