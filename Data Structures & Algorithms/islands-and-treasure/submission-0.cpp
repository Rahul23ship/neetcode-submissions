class Solution {
    int inf=2147483647;
public:

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)q.push({i,j});
            }
        }
        vector<pair<int, int>> dir = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(auto [dx,dy]:dir){
                int nx=x+dx;
                int ny=y+dy;
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==inf){
                    grid[nx][ny]=grid[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }

};
