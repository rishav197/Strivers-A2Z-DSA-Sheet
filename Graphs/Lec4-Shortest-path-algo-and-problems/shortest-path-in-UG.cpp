class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        
        int N = adj.size();
        int dist[N];
        
        for(int i=0; i<N; i++){
            dist[i]=1e9;
        }
        
        dist[src]=0;
        queue<int> q;
        q.push(src);
        
        //do bfs
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            for(auto neighbour : adj[frontNode]){
                if(dist[frontNode] + 1 < dist[neighbour]){
                    dist[neighbour] = dist[frontNode]+1;
                    q.push(neighbour);
                }
            }
        }
        
        vector<int> ans(N, -1);
        for(int i=0; i<N; i++){
            if(dist[i]!=1e9){
                ans[i] = dist[i];
            }   
        }
        
        return ans;
    }
};