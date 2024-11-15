class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        queue<int> q;
        unordered_map<int, bool> visited;
        
        q.push(0);
        visited[0]=true;
    
    
        vector<int> ans;
        //logic starts here
        while(!q.empty()){
            int topNode = q.front();
            q.pop();
            
            ans.push_back(topNode);
            
            //processing neighbouring nodes of the topNode
            for(auto node : adj[topNode]){
                if(!visited[node]){
                    q.push(node);
                    visited[node]=true;
                }
            }
        }
        
        return ans;
    }
};