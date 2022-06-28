//https://leetcode.com/problems/burst-balloons/

class Solution {
public:
    
    int solve(int i, int j, vector<int>& a, vector<vector<int>>& dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        
        for(int k = i; k <= j; k++){
            int cost = a[i-1] * a[k] * a[j+1] + 
                solve(i, k-1, a, dp) + solve(k+1, j ,a , dp);
            maxi = max(maxi,cost);
        }
        return maxi;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(1,n,nums,dp);
        
    }
};

