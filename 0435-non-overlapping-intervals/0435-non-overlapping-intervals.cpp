class Solution {
public:
    static bool comp(const vector<int>& val1, const vector<int>& val2) {
        return val1[1] < val2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), comp);
        int end = intervals[0][1];
        int cnt = 1;
        int n = intervals.size();

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= end) {
                cnt++;
                end = intervals[i][1];
            }
        }

        return n - cnt;
    }
};
