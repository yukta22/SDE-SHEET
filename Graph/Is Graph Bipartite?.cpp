//https://leetcode.com/problems/is-graph-bipartite/

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
