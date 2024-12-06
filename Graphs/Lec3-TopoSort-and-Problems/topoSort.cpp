class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    
    void topoSort(int node, vector<vector<int>>& adj, unordered_map<int,bool> &visited, stack<int> &s){
        visited[node]=true;
        
        //traverse neighbours
        for(auto neighbour : adj[node]){
            
            if(!visited[neighbour]){
                topoSort(neighbour, adj, visited, s);   
            }
        }
        
        //when returing back from a recursive call
        s.push(node);
    }
    
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        
        unordered_map<int,bool> visited;
        
        int v = adj.size();
        // cout<<v<<endl;
        
        stack<int> s;
        
        //calling topoSort for each vertex
        for(int i=0; i<v; i++){
            if(!visited[i]){
                topoSort(i, adj, visited, s);
            }
        }
        
        vector<int> ans;
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};