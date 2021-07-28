//https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1
class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int n = Matrix.size();
        int m = Matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                
                // When all paths are possible
                if(j > 0 && j < m -1){
                    Matrix[i][j] += max(Matrix[i-1][j],max(Matrix[i-1][j-1],
                                            Matrix[i-1][j+1]));
                }
                
                // When diagonal right is not possible
                else if(j > 0){
                    Matrix[i][j] += max(Matrix[i - 1][j],Matrix[i - 1][j - 1]);
                }
                
                // When diagonal left is not possible
                else if (j < m - 1){
                    Matrix[i][j] += max(Matrix[i - 1][j],Matrix[i - 1][j + 1]);
                }
            }
        }
        
        int ans = 0 ;
        for(int j = 0 ; j < m ; j ++){
            ans = max(Matrix[n-1][j] , ans);
        }
        return ans;
    }
};
