class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            int n = numCourses;
            int m = prerequisites.size();
    
            vector<vector<int>> adj(n);
            for(int i=0; i<m; i++){
                int u = prerequisites[i][1];
                int v = prerequisites[i][0];
    
                adj[u].push_back(v);
            }
    
    
            //1. find indegrees of all nodes
            vector<int> indegree(n);
            for(auto i : adj){
                for(auto j : i){
                    indegree[j]++;
                }
            }
    
            //2. push 0 indegree node to the queue 
            queue<int> q;
            for(int i=0; i<n; i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }
    
            //3. do BFS
            int count=0;
            vector<int> ans;
            while(!q.empty()){
                int topNode = q.front();
                q.pop();
    
                count+=1;
                ans.push_back(topNode);
    
                for(auto ngr : adj[topNode]){
                    indegree[ngr]--;
                    if(indegree[ngr]==0){
                        q.push(ngr);
                    }
                }
            }
    
            if(count!=n){ //invalid topo
                return {};
            }
    
            return ans; //valid topo
        }
    };