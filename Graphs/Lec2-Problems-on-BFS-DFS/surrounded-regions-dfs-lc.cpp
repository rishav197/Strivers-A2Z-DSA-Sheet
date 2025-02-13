class Solution {
    int delrow[4] = {-1, 0, +1, 0};
    int delcol[4] = {0, +1, 0, -1};

public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board, int m, int n){
        //mark visited 
        vis[row][col]=1;

        //check top, right, bottom & left
        for(int i=0; i<=3; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i]; 

            if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and !vis[nrow][ncol] and board[nrow][ncol]=='O'){
                dfs(nrow, ncol, vis, board, m, n);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(); //rows 
        int n = board[0].size(); //cols

        //vis[][]
        vector<vector<int>> vis(m, vector<int>(n, 0));

        //traverse first & last row (for boundary cells)
        for(int j=0; j<n; j++){
            if(!vis[0][j] and board[0][j]=='O'){
                dfs(0, j, vis, board, m, n);
            }
            if(!vis[m-1][j] and board[m-1][j]=='O'){
                dfs(m-1, j, vis, board, m, n);
            }
        }

        //traverse first & last col (for boundary cells)
        for(int i=0; i<m; i++){
            if(!vis[i][0] and board[i][0]=='O'){
                dfs(i, 0, vis, board, m, n);
            }
            if(!vis[i][n-1] and board[i][n-1]=='O'){
                dfs(i, n-1, vis, board, m, n);
            }
        }

        //traverse whole board for remaining O's
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] and board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }

    }
};