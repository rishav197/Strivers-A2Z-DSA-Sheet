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

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n+1);

        for(int i=0; i<n; i++){

            for(int j=0; j<n; j++){

                if(isConnected[i][j]==1){
                    if(i==j){
                        continue;
                    }
                    else{
                        adj[i+1].push_back(j+1);
                    }
                }
            }
        }

        unordered_map<int, bool> visited;
        vector<int> ans;

        //To count all provinces
        int count = 0;
        for(int node=1; node<=n; node++){

            if(!visited[node]){
                bfsTrsl(adj, visited, ans, node);
                count += 1;
            }
        }

        return count;
    }
};