//https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0 , right = height.size()-1 , water = 0;
        
        while(left < right){
            
            int h = min(height[left] , height[right]);
            int l = right - left;
            
            int currentWater = h * l;
            water = max(water, currentWater);    
            
            if(height[left] > height[right])  right--;
            else left++;
            
        }
        
        return water;
        
    }
};
