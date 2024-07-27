class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       map<int,int>mpp;
        mpp[0]=1;
        int preSum=0, cnt=0;
        for(int i=0;i<nums.size();i++){
            preSum += nums[i];
            int rem = preSum-goal;
            cnt += mpp[rem];
            mpp[preSum] += 1;
        }
        return cnt;
    }
};