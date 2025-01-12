// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        
        int v = adj.size();
        vector<int> dist(v, INT_MAX);
        
        // [dist, node]        
        set<pair<int,int>> s;
        
        
        dist[src]=0;
        s.insert({0, src});

        while(!s.empty()){
            //fetch top record
            auto topPair = *(s.begin());
            s.erase(topPair);
            
            int nodeDist = topPair.first;
            int topNode = topPair.second;
            
            //traverse ngrs
            for(auto i : adj[topNode]){
                
                if(nodeDist + i.second < dist[i.first]){
                    
                    if(dist[i.first]!=INT_MAX){
                        s.erase({dist[i.first], i.first});
                    }
                    //distance update
                    dist[i.first] = nodeDist + i.second;
                    
                    //record push 
                    s.insert({dist[i.first], i.first});
                }
            }
            
        }
        
        return dist;
    }
};