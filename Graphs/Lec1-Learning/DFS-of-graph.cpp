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