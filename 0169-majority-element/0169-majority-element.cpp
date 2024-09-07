class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(mpp[nums[i]] > n/2){
                return nums[i];
            }
        }
        return -1;
    }
};