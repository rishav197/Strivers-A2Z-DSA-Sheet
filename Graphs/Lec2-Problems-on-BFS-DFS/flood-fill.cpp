class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            //base case
            if(image[sr][sc]==color){
                return image;
            }
    
            int m = image.size();
            int n = image[0].size();
    
            queue<pair<int,int>> q;
            int oldColor = image[sr][sc];
            q.push({sr, sc});
            image[sr][sc]=color;
    
            //delta row and delta col
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
    
            
            while(!q.empty()){
                auto top = q.front();
                q.pop();
    
                int r = top.first;
                int c = top.second;
    
                for(int i=0; i<4; i++){
                    int nrow = r + drow[i];
                    int ncol = c + dcol[i];
    
                    if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and image[nrow][ncol]==oldColor){
                        image[nrow][ncol]=color;
                        q.push({nrow, ncol});
                    }
                }   
            }
    
            return image;
        }
    };

    