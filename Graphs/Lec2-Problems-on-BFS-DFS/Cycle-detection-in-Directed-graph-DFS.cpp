class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool isCycleDetected(int node, vector<vector<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited){
        visited[node]=1;
        dfsVisited[node]=1;
        
        //traverse all connected nodes 
        for(auto nbr : adj[node]){
            
            if(!visited[nbr]){
                bool ans = isCycleDetected(nbr, adj, visited, dfsVisited);
                if(ans){
                    return true;
                }
            }
            else if(dfsVisited[nbr]==true){
                return true;
            }
        }
        
        dfsVisited[node]=!dfsVisited[node];
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> adj) {

        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;
        
        //for all components
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool ans = isCycleDetected(i, adj, visited, dfsVisited);
                
                if(ans){
                    return true;
                }
            }
        }
        
        return false;
    }
};