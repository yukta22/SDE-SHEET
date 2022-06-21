//https://leetcode.com/problems/coin-change/

class Solution {
public:
    
    int dp[12 + 1][10000 + 1];
    
    int tabulation(vector<int> &coins, int n, int amount) {
        for (int i = 0; i < n + 1; i++)
            for (int j = 0; j < amount + 1; j++)
                if (i == 0 || j == 0)
                    dp[i][j] = (j == 0) ? 0 : INT_MAX - 1;
        
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < amount + 1; j++) {
                if (coins[i - 1] <= j)
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
                    
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        
        return dp[n][amount];
    }


    
    int coinChange(vector<int>& coins, int amount) {
        
        int minCoins = tabulation(coins, coins.size() , amount);
        return minCoins == INT_MAX - 1 ? -1 : minCoins;    

    }
};
