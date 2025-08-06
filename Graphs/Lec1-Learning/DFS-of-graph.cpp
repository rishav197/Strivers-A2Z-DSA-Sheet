class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node){
        ans.push_back(node); //store answer
        visited[node]=true; //mark visited
        
        
        //processing all neighbour nodes of the connected node
        for(auto i : adj[node]){
            
            if(!visited[i]){
                dfs(adj, visited, ans, i);
            }            
        }

    }
    
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        
        unordered_map<int, bool> visited;
        vector<int> ans;
        
        dfs(adj, visited, ans, 0);
        
        return ans;   
    }
};




/* ------------------------------------------------------ */ 
class Solution {
  public:
    void dfsTrsl(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &ans, int node){
        ans.push_back(node); //store answer
        vis[node]=1; //mark visited
        
        //traverse all neighbours of the node
        for(auto ngr : adj[node]){
            if(!vis[ngr]){
                //recursive call
                dfsTrsl(adj, vis, ans, ngr); 
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        
        int n = adj.size();
        vector<int> ans; 
        vector<bool> vis(n, 0);
        
        int srcNode = 0;
        dfsTrsl(adj, vis, ans, srcNode);
        
        return ans;
        
    }
};