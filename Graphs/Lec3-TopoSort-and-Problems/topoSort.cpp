/**/

class Solution {
    public:
      void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &topo){
          //mark visited
          vis[node]=1;
          
          //traverse neighbours 
          for(auto ngr : adj[node]){
              if(!vis[ngr]){
                  dfs(ngr, vis, adj, topo);
              }
          }
          
          //while returning from a recursive call
          topo.push(node);
      }
      
      // Function to return list containing vertices in Topological order.
      vector<int> topologicalSort(vector<vector<int>>& adj) {
          
          int v = adj.size();
          vector<int> vis(v, 0);
          stack<int> topo;
          
          for(int i=0; i<v; i++){
              if(!vis[i]){
                  //call dfs for each node
                  dfs(i, vis, adj, topo);    
              }
          }
          
          //stores topo order
          vector<int> ans;
          
          while(!topo.empty()){
              auto top = topo.top();
              topo.pop();
              
              ans.push_back(top);
          }
          
          return ans;
      }
  };