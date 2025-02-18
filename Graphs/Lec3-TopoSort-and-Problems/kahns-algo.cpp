class Solution {
    public:
      // Function to return list containing vertices in Topological order.
      vector<int> topologicalSort(vector<vector<int>>& adj) {
          int v = adj.size(); //nodes
          
          vector<int> indegree(v, 0);
          
          //step1 : indegree calc for all nodes
          for(int i=0; i<v; i++){
              for(auto node : adj[i]){
                  indegree[node]++;
              }    
          }
          
          //step2 : 0 degree walo ko push kardo
          queue<int> q;
          for(int i=0; i<v; i++){
              if(indegree[i]==0){
                  q.push(i);
              }
          }
          
          
          //step3 : Do BFS
          vector<int> ans;
          
          while(!q.empty()){
              auto topNode = q.front();
              q.pop();
              
              //store answer
              ans.push_back(topNode);
              
              for(auto ngr : adj[topNode]){
                  
                  indegree[ngr]--; //decrease indeg by 1
                  if(indegree[ngr]==0){ //check if ngr has indeg=0
                      q.push(ngr);
                  }
              }
          }
          
          return ans;
          
      }
  };