class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        
        int n = V;
        int m = edges.size();


        vector<vector<int>> adjMat(n);        
        for(int i=0; i<m; i++){
            int u = edges[i].first;
            int v = edges[i].second;
            
            adjMat[u].push_back(v);
            adjMat[v].push_back(u);
        }
    
        
        return adjMat;
    }
};