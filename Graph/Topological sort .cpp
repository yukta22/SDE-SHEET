//https://practice.geeksforgeeks.org/problems/topological-sort/1#


////////////////////////////////////////////////////// BFS //////////////////////////////////////////////////////
class Solution
{
	public:

  vector<int> topoSort(int V, vector<int> adj[]){
	    queue<int> q;
	    vector<int> indegree(V,0);
	    
	    for(int i = 0 ; i < V ; i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    for(int i = 0 ; i < V ; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    vector<int> topo;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(auto it : adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    return topo;
	}
};

////////////////////////////////////////////////////// DFS //////////////////////////////////////////////////////

class Solution
{
	private:
    void findToposort(int node,vector<int> &vis,stack<int>& st ,vector<int> adj[]){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                findToposort(it,vis,st,adj);
            }
        }
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    stack<int> st;
	    vector<int> vis(V,0);
	    for(int i = 0 ; i < V ; i++){
	        if(vis[i] == 0){
	            findToposort(i,vis,st,adj);
	        }
	    }
	    vector<int> topo;
	    while(!st.empty()){
	        topo.push_back(st.top());
	        st.pop();
	    }
	    return topo;
	}
};

