int knapSack(int W, int wt[], int val[], int n) 
{ 
      int t[n+1][W+1];
      for(int i = 0 ; i < n+1 ; i++)
          for(int j = 0 ; j < W+1 ; j++)
              if(i == 0 || j == 0)
                  t[i][j] = 0;

      for(int i = 1 ; i < n+1 ; i++){
          for(int j = 1 ; j < W+1 ; j++){
              if(wt[i-1] <= j){
                  t[i][j] = max(val[i-1] + t[i-1][j - wt[i-1]] , t[i-1][j]);
              }
              else{
                  t[i][j] = t[i-1][j];
              }
          }
      }

      return t[n][W];
 }


//////////////////////////////////////////////////////////////////////////////////////////////////////////

int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int> (maxWeight+1,0));
    
    for(int i = wt[0] ; i <= maxWeight ; i++){
        dp[0][i] = val[0];
    }
    
    for(int ind = 1; ind < n; ind++){
        for(int W = 0 ; W <= maxWeight; W++){
            int notTake = 0 + dp[ind-1][W];
            int take = INT_MIN;
            if(wt[ind] <= W){
                take = val[ind] + dp[ind-1][W - wt[ind]];
            }
            dp[ind][W] = max(take,notTake);
        }
    }
    return dp[n-1][maxWeight];
	
}


/////////////////////////////////////////////////////Single Array Space Optimised Approach/////////////////////////////////////////////////////

int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
    vector<int> prev(maxWeight+1,0) , curr(maxWeight+1,0);
    
    for(int i = wt[0] ; i <= maxWeight ; i++){
        prev[i] = val[0];
    }
    
    for(int ind = 1; ind<n ; ind++){
        for(int W = 0 ; W <= maxWeight; W++){
            int notTake = 0 + prev[W];
            int take = INT_MIN;
            if(wt[ind] <= W){
                take = val[ind] + prev[W - wt[ind]];
            }
            curr[W] = max(take,notTake);
        }
        prev = curr;
    }
    return prev[maxWeight];
	
}



