// User function Template for C++

class Solution {
    private:
        int delrow[4] = {-1, 0, +1, 0};
        int delcol[4] = {0, -1, 0, +1};
        
      public:
        void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int,int>> &vt, int row0, int col0){
            vis[row][col]=1;
            vt.push_back({row - row0, col-col0});
            
            int n = grid.size();
            int m = grid[0].size();
            
            for(int i=0; i<=3; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol]==1){
                    dfs(nrow, ncol, vis, grid, vt, row0, col0);
                }
            }
        }
        
        int countDistinctIslands(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            
            //vis[][]
            vector<vector<int>> vis(n, vector<int>(m, 0));
            
            set<vector<pair<int,int>>> st;
            
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!vis[i][j] and grid[i][j]==1){
                        vector<pair<int,int>> vt;
                        // nxmx4
                        dfs(i, j, vis, grid, vt, i, j);
                        st.insert(vt);
                    }
                }
            }
            
            // n x m x log(set length) + (n x m x 4)
            return st.size(); //no. of distinct islands
            
        }
    };