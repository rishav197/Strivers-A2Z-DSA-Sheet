// User function Template for C++

class Solution {
    public:
      void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int delrow[], int delcol[]){
          //mark visited
          vis[row][col]=1;
          
          int n = mat.size();
          int m = mat[0].size();
          
          //check for top, right, bottom & left
          for(int i=0; i<4; i++){
              int nrow = row + delrow[i]; 
              int ncol = col + delcol[i];
              
              if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and mat[nrow][ncol]=='O'){
                  dfs(nrow, ncol, vis, mat, delrow, delcol);
              }
          }
      }
      
      vector<vector<char>> fill(vector<vector<char>>& mat) {
          
          int n = mat.size();
          int m = mat[0].size();
          
          //delta row & col
          int delrow[] = {-1, 0, +1, 0};
          int delcol[] = {0, +1, 0, -1};
          
          // vis[][] 
          vector<vector<int>> vis(n, vector<int>(m, 0));
          
          //traverse first & last row
          for(int j=0; j<m; j++){
              //first row
              if(!vis[0][j] and mat[0][j]=='O'){
                  dfs(0, j, vis, mat, delrow, delcol);
              }
              
              //last row
              if(!vis[n-1][j] and mat[n-1][j]=='O'){
                  dfs(n-1, j, vis, mat, delrow, delcol);
              }
          }
          
          //traverse first & last column
          for(int i=0; i<n; i++){
              //first col
              if(!vis[i][0] and mat[i][0]=='O'){
                  dfs(i, 0, vis, mat, delrow, delcol);
              }
              
              //last col
              if(!vis[i][m-1] and mat[i][m-1]=='O'){
                  dfs(i, m-1, vis, mat, delrow, delcol);
              }
          }
          
          
          //for remaining O's
          for(int i=0; i<n; i++){
              for(int j=0; j<m; j++){
                  if(!vis[i][j] and mat[i][j]=='O'){
                      mat[i][j]='X';
                  }
              }
          }
          
          return mat;
      }
  };

  