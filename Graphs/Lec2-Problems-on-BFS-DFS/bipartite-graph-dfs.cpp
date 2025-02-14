class Solution {
    bool dfs(int node, int col, int color[], vector<vector<int>> &adj){
        color[node] = col;
        
        for(auto ngr : adj[node]){
            if(color[ngr]==-1){
                bool ans = dfs(ngr, !col, color, adj);
                if(ans==false){
                    return false;
                }
            }
            else if(color[ngr]==col){
                return false;
            }
        }
        
        return true;
    }
    
  public:
    bool isBipartite(vector<vector<int>>& adj) {
        int v = adj.size();
        int color[v];
        
        for(int i=0; i<v; i++){
            color[i]=-1;
        }
        
        for(int i=0; i<v; i++){
            if(color[i]==-1){
                if(dfs(i, 0, color, adj)==false){
                    return false;
                }
            }
        }
        
        return true;
        
    }
};

