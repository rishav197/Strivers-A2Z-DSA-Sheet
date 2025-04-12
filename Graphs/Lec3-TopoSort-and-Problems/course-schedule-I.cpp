/* tc -> O(N+M)
*/

class Solution {
    public:
    
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            
            int n = numCourses;
            int m = prerequisites.size();
    
            vector<vector<int>> adj(n);
    
            for(int i=0; i<m; i++){
                int v = prerequisites[i][0];
                int u = prerequisites[i][1];
    
                adj[u].push_back(v);
            }
    
            //find all degrees
            vector<int> indegree(n);
            for(auto i : adj){
                for(auto j : i){
                    indegree[j]++;
                }
            }
    
    
            //add 0 degree nodes to the queue
            queue<int> q;
            for(int i=0; i<n; i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }
    
            //do BFS
            int count=0;
            while(!q.empty()){
                int topNode = q.front();
                q.pop();
    
                count+=1;
    
                //traverse all ngrs
                for(auto ngr : adj[topNode]){
                    indegree[ngr]--;
                    if(indegree[ngr]==0){
                        q.push(ngr);
                    }
                }
            }
    
            if(count!=n){ //invalid topoSort
                return false;
            }
    
            return true; //valid topoSort
        }
    };

