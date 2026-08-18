class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int p = 0;

        for (int i = 0; i < a.size(); ++i) {
            if (p < 2 || a[i] != a[p - 2]) {
                swap(a[i], a[p]);
                ++p;
            }
        }

        return p;

    }
};
