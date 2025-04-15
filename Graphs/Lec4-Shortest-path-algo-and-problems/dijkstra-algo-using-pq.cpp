
// User Function Template
class Solution {
    public:
      vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
          
          // Step 1: Build adjacency list
          vector<vector<pair<int, int>>> adj(V);
          for (int i = 0; i < edges.size(); i++) {
              int u = edges[i][0];
              int v = edges[i][1];
              int w = edges[i][2];
          
              adj[u].push_back({v, w});
              adj[v].push_back({u, w}); // if graph is undirected
          }
      
          // Step 2: Initialize distance vector and priority queue
          vector<int> dist(V, 1e9);
          dist[src] = 0;
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
          pq.push({0, src}); // {distance, node}
      
          // Step 3: Dijkstra's algorithm
          while (!pq.empty()) {
              int dis = pq.top().first;
              int node = pq.top().second;
              pq.pop();
          
              for (auto it : adj[node]) {
                  int adjNode = it.first;
                  int edgeWt = it.second;
              
                  if (dis + edgeWt < dist[adjNode]) {
                      dist[adjNode] = dis + edgeWt;
                      pq.push({dist[adjNode], adjNode});
                  }
              }
          }
        
          return dist;
      }
  };
  