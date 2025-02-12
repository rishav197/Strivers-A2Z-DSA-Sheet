class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int m = mat.size();
            int n = mat[0].size();
    
            //vis[][]
            vector<vector<int>> vis(m, vector<int>(n, 0));
    
            //dist[][] -- answer 
            vector<vector<int>> dist(m, vector<int>(n, 0));
    
            queue<pair<pair<int,int>, int>> q;
    
            //Initialize all 0's
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(mat[i][j]==0){
                        vis[i][j]=1;
                        q.push({{i,j}, 0});
                    }
                }
            }
    
            //delta row & col
            int delrow[] = {-1, 0, +1, 0}; 
            int delcol[] = {0, -1, 0, +1};
    
            while(!q.empty()){
                auto top = q.front();
                q.pop();
    
                int row = top.first.first;
                int col = top.first.second;
                int d = top.second;
    
                dist[row][col] = d;
    
                for(int idx=0; idx<=3; idx++){
                    int nrow = row + delrow[idx];
                    int ncol = col + delcol[idx];
    
                    if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and vis[nrow][ncol]==0){
                        vis[nrow][ncol]=1;
                        q.push({{nrow,ncol}, d+1});
                    }
                }
            }
    
            return dist;
        }
    };