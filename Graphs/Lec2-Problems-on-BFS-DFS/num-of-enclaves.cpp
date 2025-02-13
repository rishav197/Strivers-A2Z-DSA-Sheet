class Solution {
    int delrow[4] = {-1, 0, +1, 0};
    int delcol[4] = {0, +1, 0, -1};

public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int m, int n){
        //mark visited
        vis[row][col]=1;

        //check top, right, bottom and left
        for(int i=0; i<=3; i++){
            int nrow = row + delrow[i]; //new row
            int ncol = col + delcol[i]; //new col

            if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and !vis[nrow][ncol] and grid[nrow][ncol]==1){
                dfs(nrow, ncol, vis, grid, m, n);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(); //rows
        int n = grid[0].size(); //cols

        //vis[][]
        vector<vector<int>> vis(m, vector<int>(n, 0));

        //traverse boundary cells 
        //traverse first & last row
        for(int j=0; j<n; j++){
            if(!vis[0][j] and grid[0][j]==1){
                dfs(0, j, vis, grid, m, n);
            }
            if(!vis[m-1][j] and grid[m-1][j]==1){
                dfs(m-1, j, vis, grid, m, n);
            }
        }


        //traverse first & last col
        for(int i=0; i<m; i++){
            if(!vis[i][0] and grid[i][0]==1){
                dfs(i, 0, vis, grid, m, n);
            }
            if(!vis[i][n-1] and grid[i][n-1]==1){
                dfs(i, n-1, vis, grid, m, n);
            }
        }

        //traverse whole grid for remaining land cells or 1s
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] and grid[i][j]==1){
                    ans++;
                }
            }
        }

        return ans;
    }
};
