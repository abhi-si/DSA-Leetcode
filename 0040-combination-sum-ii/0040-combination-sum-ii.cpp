class Solution {
public:
    void findCombinationSum(int ind, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > ind && candidates[i] == candidates[i - 1]) continue;
            // Break if the candidate is greater than the target
            if (candidates[i] > target) break;
            ds.push_back(candidates[i]);
            // Move to the next index since each candidate can be used only once
            findCombinationSum(i + 1, target - candidates[i], candidates, ans, ds);
            // Backtrack
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        // Sort candidates to handle duplicates
        sort(candidates.begin(), candidates.end());
        findCombinationSum(0, target, candidates, ans, ds);
        return ans;
    }
};
