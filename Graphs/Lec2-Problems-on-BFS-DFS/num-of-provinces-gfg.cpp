//User function Template for C++

class Solution {
  public:
    void bfsTrsl(vector<vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int srcNode){
        queue<int> q;
        q.push(srcNode);
        visited[srcNode]=true;
        
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            //store answer into vector ans
            ans.push_back(frontNode);
            
            //traverse all neighbours of frontNode
            for(auto node : adj[frontNode]){
                
                if(!visited[node]){
                    q.push(node);
                    visited[node] = true;
                }
            }

        }
        
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        //Create an adj list
        int n = adj.size();
        vector<vector<int>> adjList(n+1);
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<n; j++){
                
                if(adj[i][j]==1){
                    if(i==j){
                        continue;
                    }   
                    else{
                        adjList[i+1].push_back(j+1);
                    }
                }
            }
        }
        

        unordered_map<int, bool> visited;
        vector<int> ans;
        
        int count = 0;
        //To count all provinces
        for(int i=1; i<=V; i++){
            
            if(!visited[i]){
                bfsTrsl(adjList, visited, ans, i);
                count += 1;
            }
        }

        return count;
        
    }
};