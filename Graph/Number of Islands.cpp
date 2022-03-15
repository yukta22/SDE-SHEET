//https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.size() == 0) return 0;
        
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        int m = grid[0].size();
        int n = grid.size();
        
        int island = 0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1'){
                    island++;
                    q.emplace(make_pair(i,j));
                    
                    while(!q.empty()){
                        auto f = q.front();
                        q.pop();
                        int x = f.first;
                        int y = f.second;
                        
                        if(grid[x][y] == '1'){
                            grid[x][y] = 0;
                            
                            for(auto d : dir) { 
                                int a = x + d[0];
                                int b = y + d[1];
                                if(a>=0 && a<n && b>=0 && b<m)
                                    q.emplace(make_pair(a, b));
                            }

                        }
                        
                    }

                }
                
            }
        }
    
        return island;

        
    }
};
