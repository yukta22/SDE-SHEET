//https://leetcode.com/problems/maximum-subarray/

//////////////////////////////// kadane's algorithm///////////////////////
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];
        
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            maxi = max(maxi,sum);
            
            if(sum<0) sum=0;
            
        }
        return maxi;
      
    }
};

///////////////////////using dp/////////////////
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();        
        int dp[n];
        
        dp[0] = nums[0];
        int maxi = nums[0];
        
        for(int i = 1 ;i < n ; i++){
            dp[i] = max(nums[i] , nums[i] + dp[i-1]);
            maxi = max(maxi , dp[i]);
        }
        return maxi;
        
    }
};

