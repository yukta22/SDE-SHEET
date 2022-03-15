//https://leetcode.com/problems/course-schedule/

class Solution {
     bool checkforCycle(int node , vector<int>&cur , vector<int>&vis , vector<vector<int>>&adj){
         vis[node] = 1;
         cur[node] = 1;
         
        for(auto it : adj[node]){
            if(vis[it] == 0){
                if(checkforCycle(it,cur,vis,adj) == false)return false;
            }
            else if(cur[it]){
                return false;
            }    
        } 
        cur[node] = 0;
        return true;    
    }
public:
    bool canFinish(int num, vector<vector<int>>& prerequisites) {
        
         vector<vector<int>>adj(num+1);
          for(auto x:prerequisites){
            adj[x[0]].push_back(x[1]);
          }
        vector<int>vis(num+1,0);
        vector<int>cur(num+1,0);
     for(int i = 0;i<num;i++){
         if(!vis[i]){
             if(!checkforCycle(i,cur,vis,adj)) return false;
         } 
     }
     return true;
    }
};
