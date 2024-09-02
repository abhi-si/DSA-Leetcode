class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0 , r =n-1 , maxWater =0;
        while(l < r){
            int w = r-l;
            int h = min(height[l],height[r]);
            int area = w*h;
            maxWater = max(maxWater,area);
            if(height[l] < height[r]) l++;
            else if(height[r] < height[l]) r--;
            else{
                l++;
                r--;
            }
        }
        return maxWater;
    }
};