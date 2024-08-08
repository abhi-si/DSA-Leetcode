class Solution {
public:
    struct Job {
        int start, end, profit;
    };

    static bool comparison(Job a, Job b) {
        return a.end < b.end;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> jobs(n);

        // Fill jobs vector
        for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }

        // Sort jobs based on end time
        sort(jobs.begin(), jobs.end(), comparison);

        // Vector to store the maximum profit until each job
        vector<int> maxProfit(n, 0);
        maxProfit[0] = jobs[0].profit;

        for (int i = 1; i < n; i++) {
            // Include the current job's profit
            int inclProfit = jobs[i].profit;

            // Find the latest job that doesn't conflict with the current job
            for (int j = i - 1; j >= 0; j--) {
                if (jobs[j].end <= jobs[i].start) {
                    inclProfit += maxProfit[j];
                    break;
                }
            }

            // Store the maximum profit by including or excluding the current job
            maxProfit[i] = max(inclProfit, maxProfit[i - 1]);
        }

        // The last element of maxProfit will have the maximum profit
        return *max_element(maxProfit.begin(), maxProfit.end());
    }
};