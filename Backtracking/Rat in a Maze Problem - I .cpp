//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

//////////////////////////////////////////////////////////////// Approach 1 ////////////////////////////////////////////////////////////////

class Solution{
    public:
    vector<string> v;
    void dfs(int i,int j,string s,vector<vector<int>> &m,int n,vector<vector<int>> &vis){
        if(i<0 || j < 0 || i>=n || j>=n)  return;
        if(m[i][j] == 0 || vis[i][j] == 1) return;
        
        if(i==n-1 && j == n-1){
            v.push_back(s);
            return;
        }
        
        vis[i][j] = 1;
        
        dfs(i-1,j,s+'U',m,n,vis);
        dfs(i+1,j,s+'D',m,n,vis);
        dfs(i,j-1,s+'L',m,n,vis);
        dfs(i,j+1,s+'R',m,n,vis);
        
        vis[i][j] = 0;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        v.clear();
        vector<vector<int>> vis(n, vector<int> (n,0)); 
        if(m[0][0] == 0) return v;
        if(m[n-1][n-1] == 0) return v;
        
        string s ="";
        
        dfs(0,0,s,m,n,vis);
        sort(v.begin(),v.end());
        return v;
        
    }
  
//////////////////////////////////////////////////////////////// Approach 2 ////////////////////////////////////////////////////////////////

class Solution{
    public:
    vector<string> v;
        void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, 
    vector<vector<int>> &vis) {
        if(i==n-1 && j==n-1) {
            ans.push_back(move);
            return; 
        }
        
        // downward
        if(i+1<n && !vis[i+1][j] && a[i+1][j] == 1) {
            vis[i][j] = 1; 
            solve(i+1, j, a, n, ans, move + 'D', vis);
            vis[i][j] = 0; 
        }
        
        // // left
        if(j-1>=0 && !vis[i][j-1] && a[i][j-1] == 1) {
            vis[i][j] = 1; 
            solve(i, j-1, a, n, ans, move + 'L', vis);
            vis[i][j] = 0; 
        }
        
        // // right 
        if(j+1<n && !vis[i][j+1] && a[i][j+1] == 1) {
            vis[i][j] = 1; 
            solve(i, j+1, a, n, ans, move + 'R', vis);
            vis[i][j] = 0; 
        }
        
        // // upward
        if(i-1>=0 && !vis[i-1][j] && a[i-1][j] == 1) {
            vis[i][j] = 1; 
            solve(i-1, j, a, n, ans, move + 'U', vis);
            vis[i][j] = 0; 
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n, 0)); 
        
        if(m[0][0] == 1) solve(0,0,m,n, ans, "", vis); 
        return ans; 
    }

    
