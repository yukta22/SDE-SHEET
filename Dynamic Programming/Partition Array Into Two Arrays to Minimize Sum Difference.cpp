//https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int sum = 0;
        for(int i = 0 ; i< nums.size() ; i++){
            sum += nums[i];
        }
        
        int n = nums.size();
        bool dp[n+1][sum+1];
        for(int i=0;i<=n;i++) dp[i][0] = true; 
        for(int j=0;j<=sum;j++) dp[0][j] = false; 
        
        for(int i = 1; i <= n; i++){
            for(int j = 1 ; j <= sum ; j ++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        int mini = 1e9;
        for(int s1 = 0 ; s1 <= sum/2 ; s1++){
            if(dp[n-1][s1] == true){
                mini = min(mini , abs((sum-s1)-s1));
            }
        }
        return mini;
    }
};

