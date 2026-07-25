class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1)fresh++;
            }
        }
        if(fresh==0)return 0;
        int level=-1;
        vector<pair<int,int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(auto [dx,dy]:dir){
                    int nx=x+dx;int ny=y+dy;
                    if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny]==1){
                        q.push({nx,ny});
                        grid[nx][ny]=2;
                    }
                }
            }
            level++;
            
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return level;
    }
};
