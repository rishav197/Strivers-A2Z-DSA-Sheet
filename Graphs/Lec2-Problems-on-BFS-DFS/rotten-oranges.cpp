/*
tc -> O(N*M)+O(4*N*M)~O(N*M), sc -> O(N*M)
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // {{row, col}, time}

        queue<pair<pair<int,int>, int>> q;
        int vis[n][m];
        int cntFresh = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(grid[i][j]==2){
                    q.push({{i,j}, 0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }

                if(grid[i][j]==1){
                    cntFresh++;
                }
            }
        }

        int time = 0;
        //delta row and delta col
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int cnt=0;

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            int r = top.first.first;
            int c = top.first.second;
            int t = top.second;
            time = max(time, t);

            //Rottening all fresh neighbours 
            for(int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol}, t+1});
                    vis[nrow][ncol]=2; //visited
                    cnt++;
                }             
            }
        }

        if(cnt!=cntFresh) return -1;

        return time;
    }
};