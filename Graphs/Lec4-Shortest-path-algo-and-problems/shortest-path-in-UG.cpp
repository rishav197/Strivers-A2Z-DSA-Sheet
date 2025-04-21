/* approach 1 : Using BFS and dist[] array
*/

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


/*
approach 2 : using BFS, Visited[] array and Parent mapping when both source and destination nodes are given
*/

#include<unordered_map>
#include<queue>
#include<list>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	//create adjacency list
	unordered_map<int, list<int>> adj;

	for(int i=0; i<edges.size(); i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u); //for undirected graph
	}

	//do BFS
	unordered_map<int, bool> visited;
	unordered_map<int, int> parent;
	queue<int> q;
	q.push(s);
	parent[s]=-1;
	visited[s]=true;

	while(!q.empty()){
		int frontNode = q.front();
		q.pop();
		
		//traverse neighbours
		for(auto i : adj[frontNode]){
			if(!visited[i]){
				visited[i] = true;
				parent[i] = frontNode;
				q.push(i);
			}
		}
	}	

	//prepare shortest path
	vector<int> ans;
	int currNode = t;
	ans.push_back(t);

	while(currNode!=s){
		currNode = parent[currNode];
		ans.push_back(currNode);
	}
	
	reverse(ans.begin(), ans.end());
	return ans;
}