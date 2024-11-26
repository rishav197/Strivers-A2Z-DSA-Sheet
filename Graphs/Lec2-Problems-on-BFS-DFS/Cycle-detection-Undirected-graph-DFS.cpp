/*approach : Cycle detection using DFS */

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool isCycleDetected(vector<vector<int>> &adj, unordered_map<int, bool> &visited, int node, int parent){
        visited[node] = true;
        
        //traverse all neighbours 
        for(auto neighbour : adj[node]){
         
            if(visited[neighbour]==true and neighbour!=parent){
                //cycle present
                return true;
            }
            else if(!visited[neighbour]){ //proceed further
               
                bool ans = isCycleDetected(adj, visited, neighbour, node);
                
                if(ans==true){
                    return true;
                }    
            }
        }
        
        return false;
    }
    
    
    bool isCycle(vector<vector<int>>& adj) {
        unordered_map<int, bool> visited;
        
        int V = adj.size();
        
        //in case of disconnected graph
        for(int i = 0; i < V; ++i) {
            
            if(!visited[i]) {
                
                bool isDetected = isCycleDetected(adj, visited, i, -1);
                if(isDetected){
                    return true;
                }    
            }
        }
        
        return false;
    }
};