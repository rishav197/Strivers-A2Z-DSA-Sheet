
// User function Template for C++
class Solution {
    public:
      void topoSort(vector<pair<int,int>> adj[], int vis[], stack<int> &st, int node){
          vis[node]=1;
          
          for(auto it : adj[node]){
              int ngr = it.first;
              if(!vis[ngr]){
                  topoSort(adj, vis, st, ngr);
              }
          }
          
          st.push(node);
      }
      
      vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
          
          vector<pair<int,int>> adj[V]; //dag
          for(int i=0; i<E; i++){
              int u = edges[i][0];
              int v = edges[i][1];
              int w = edges[i][2];
              
              adj[u].push_back({v, w});
          }
          
          //step1: find the topo sort
          int vis[V]={0};
          stack<int> st;
          for(int i=0; i<V; i++){
              if(!vis[i]){
                  topoSort(adj, vis, st, i);
              }
          }
          
          //step2: update the distance 
          vector<int> dist(V);
          for(int i=0; i<V; i++){
              dist[i]=1e9;
          }
          
          dist[0]=0;
          while(!st.empty()){
              int node = st.top();
              st.pop();
              
              for(auto it : adj[node]){
                  int v = it.first;
                  int w = it.second;
                  
                  if(dist[node]+w < dist[v]){
                      dist[v] = dist[node] + w;
                  }
              }
          }
          
          //updating dist for nodes which are unreachable
          for(int i=0; i<V; i++){
              if(dist[i]==1e9){
                  dist[i]=-1;
              }
          }
          return dist;
      }
  };
  