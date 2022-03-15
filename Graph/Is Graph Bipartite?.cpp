//https://leetcode.com/problems/is-graph-bipartite/


/////////////////////////////////////////////////// BFS ///////////////////////////////////////////////////
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n,0);
        queue<int> q;
        
        for(int i = 0; i < n ; i++){
            if(colors[i]) continue;
            
            colors[i] = 1;
            q.push(i);
            
            while(!q.empty()){
                int node = q.front();
                
                for(auto it : graph[node]){
                    if(!colors[it]){
                        colors[it] =  -colors[node];
                        q.push(it);
                    }
                    else if(colors[it] == colors[node])   return false;
                }
                q.pop();
                
            }
            
        }
        return true;
        
    }
};

/////////////////////////////////////////////////// DFS ///////////////////////////////////////////////////

class Solution {
public:
    
        bool dfs(int n,bool c,vector<vector<int>>& graph,vector<int>&color,vector<int>&visited){
        visited[n]=1;
        color[n]=c;
        for(int it:graph[n]){
            if(visited[it]==0){
                if(dfs(it,c^1,graph,color,visited)==false)return false;
            }
            else
                if(color[n]==color[it])return false;
        }
        return true;
    }

    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,0);
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                if(!(dfs(i,0,graph,color,visited)))
                       return false;
            }
        }
        return true;
    
    }
};

