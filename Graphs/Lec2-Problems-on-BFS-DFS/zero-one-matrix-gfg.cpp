class Solution {
    public:
      // Function to find distance of nearest 1 in the grid for each cell.
      vector<vector<int>> nearest(vector<vector<int>>& grid) {
          // Code here
          int n = grid.size(); //rows
          int m = grid[0].size(); //cols
          
          //vis[] 
          vector<vector<int>> vis(n, vector<int>(m, 0));
          
          //dist[]
          vector<vector<int>> dist(n, vector<int>(m, 0));
          
          
          //Using BFS
          queue<pair<pair<int,int>, int>> q;
          
          //storing all initial 1's
          for(int i=0; i<n; i++){
              for(int j=0; j<m; j++){
                  if(grid[i][j]==1){
                      q.push({{i,j}, 0});
                      vis[i][j]=1;
                  }
                  else{
                      vis[i][j]=0;
                  }
              }
          }
          
          //delta row & col
          int delrow[] = {-1, 0, +1, 0};
          int delcol[] = {0, +1, 0, -1};
          
          while(!q.empty()){
              auto top = q.front();
              q.pop();
              
              int row = top.first.first;
              int col = top.first.second;
              
              int step = top.second;
              
              //marking dist[][] grid
              dist[row][col] = step;
              
              for(int i=0; i<4; i++){
                  int nrow = row + delrow[i];
                  int ncol = col + delcol[i];
                  
                  if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0){
                      vis[nrow][ncol]=1;
                      q.push({{nrow,ncol}, step+1});
                  }
              }
              
          }
          
          return dist;
      }
  };