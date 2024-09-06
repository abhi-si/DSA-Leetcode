class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l=1 ,r = n;
        while(l < r){
            int sum = numbers[l-1] + numbers[r-1];
            if(sum == target) return {l,r};
            else if(sum < target) l++;
            else r--;
        }
        return {};

    }
};