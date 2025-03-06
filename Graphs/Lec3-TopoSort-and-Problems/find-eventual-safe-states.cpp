
// User function Template for C++

class Solution {
    public:
      vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
          // code here
          vector<int> adjRev[V];
          int indegree[V] = {0};
          
          for(int i=0; i<V; i++){
              //'it' is neighbour of 'i'
              for(auto it : adj[i]){
                  adjRev[it].push_back(i);
                  indegree[i]++;
              }
          }
          
          
          queue<int> q;
          vector<int> safeNodes;
          for(int i=0; i<V; i++){
              if(indegree[i]==0){
                  q.push(i);
              }
          }
          
          //bfs
          while(!q.empty()){
              int topNode = q.front();
              q.pop();
              safeNodes.push_back(topNode);
              
              for(auto it : adjRev[topNode]){
                  indegree[it]--;
                  
                  if(indegree[it]==0){
                      q.push(it);
                  }
              }
          }
          
          
          //sort final ans
          sort(safeNodes.begin(), safeNodes.end());
          return safeNodes;
          
      }
  };
  