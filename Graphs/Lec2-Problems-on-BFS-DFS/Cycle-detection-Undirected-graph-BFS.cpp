class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool isCycleDetected(vector<vector<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, int> &parent, int srcNode){
        parent[srcNode] = -1;
        visited[srcNode] = true;
        
        queue<int> q;
        q.push(srcNode);
        
        //BFS logic
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            for(auto neighbour : adj[frontNode]){
                
                if(visited[neighbour]==true and neighbour!=parent[frontNode]){
                    return true;
                }
                else if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour]=true;
                    parent[neighbour]=frontNode;
                }                
            }
            
        }
        
        return false;
    }
    
    
    bool isCycle(vector<vector<int>>& adj) {
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        
        int V = adj.size();
        
        //in case of disconnected graph
        for(int i = 0; i < V; ++i) {
            
            if(!visited[i]) {
                
                bool ans = isCycleDetected(adj, visited, parent, i);
                if(ans==true){
                    return ans;
                }    
            }
        }
        
        return false;
    }
};