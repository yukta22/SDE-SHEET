//https://leetcode.com/problems/house-robber-ii/


class Solution {
public:
    int solve(vector<int>& arr){
        if(arr.size() == 1) return arr[0];
        int dp[arr.size()+1];
        dp[0] = arr[0];
        dp[1] = max(arr[0],arr[1]);
        
        for(int i = 2; i<arr.size();i++){
            dp[i] = max(dp[i-1],dp[i-2] + arr[i]);
        }
        
        return dp[arr.size()-1];
    }

    
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        // either use first house and can't use last or last and not first:
        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        return max(solve(v1), solve(v2));

    }
};
