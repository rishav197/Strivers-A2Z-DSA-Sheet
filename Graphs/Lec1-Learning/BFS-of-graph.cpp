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


/*------------------------------------------------ */ 
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        
        queue<int> q;
        q.push(0);

        vector<bool> vis(n, 0);
        vis[0]=1;
        
        vector<int> ans;
        
        //trsl starts here
        while(!q.empty()){
            
            auto topNode = q.front();
            q.pop();
            ans.push_back(topNode); //storing answer
            
            for(auto ngr : adj[topNode]){
                if(!vis[ngr]){ //checking if vis[ngr] visited or not
                    q.push(ngr);
                    vis[ngr]=1;
                }
            }
        }
        
        return ans;
        
    }
};