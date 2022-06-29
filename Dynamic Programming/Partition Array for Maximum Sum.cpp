//https://leetcode.com/problems/partition-array-for-maximum-sum/

class Solution {
public:
    
    int f(int ind, vector<int>& num, int k, vector<int>& dp){
        int n = num.size();
        if(ind == n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for(int j = ind; j < min(ind + k, n); j++){
            len++;
            maxi = max(maxi, num[j]);
            int sum = len*maxi + f(j+1, num, k, dp);
            maxAns = max(maxAns, sum);
            
        }
        return dp[ind] = maxAns;
        
        
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return f(0, arr, k, dp);
    }
};

