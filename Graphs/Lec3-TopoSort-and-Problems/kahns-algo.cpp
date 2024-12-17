class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        
        int v = adj.size();
        vector<int> indegree(v);
        
        //step1: find all indegrees
        for(auto i : adj){
            
            for(auto j : i){
                indegree[j]++;
            }
        }
        
        // for(auto i : indegree){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        
        //step2: insert nodes into queue which has zero indegree
        queue<int> q;
        for(int i=0; i<v; i++){
            
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        //step3: do bfs-breath first search
        vector<int> ans;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            //ans store
            ans.push_back(frontNode);
            
            //neighbour indegree update
            for(auto neighbour : adj[frontNode]){
                indegree[neighbour]-=1;
                
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
                
            }
            
        }
        
        
        return ans;
    }
};