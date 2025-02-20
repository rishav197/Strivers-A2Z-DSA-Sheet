class Solution {
    public:
      // Function to detect cycle in a directed graph.
      bool isCyclic(vector<vector<int>> &adj) {
          int v = adj.size();
          
          //step1: find all indegrees
          vector<int> indegree(v);
          for(int i=0; i<v; i++){
              
              for(auto j : adj[i]){
                  indegree[j]++;    
              }
          }
          
          //step2: 0 indegree walo push krdo
          queue<int> q;
          for(int i=0; i<v; i++){
              if(indegree[i]==0){
                  q.push(i);
              }
          }
          
          //step3: do BFS
          int count = 0;
          while(!q.empty()){
              auto topNode = q.front();
              q.pop();
              
              //increase count
              count++;
              
              //neighbour indegree update
              for(auto ngr : adj[topNode]){
                  
                  indegree[ngr]--;    
                  if(indegree[ngr]==0){
                      q.push(ngr);
                  }
              }
          }
          
          if(count!=v){ //Invalid topoSort & cyclic
              return true;
          }
          
          return false; //Valid topoSort & acylic 
      }
  };