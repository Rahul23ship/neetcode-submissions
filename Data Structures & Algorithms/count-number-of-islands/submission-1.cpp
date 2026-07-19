class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        int island=0;
        int row=grid.size(),col=grid[0].size();
        vector<vector<bool>>vis(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    bfs(grid,vis,i,j);
                    island++;
                }
            }
        }
        return island;
    }
    
    void bfs(vector<vector<char>>&grid,vector<vector<bool>>&vis,int i,int j){
        queue<pair<int,int>>q;
        vis[i][j]=true;;
        q.push({i,j});
        vector<pair<int,int>>v{
            {-1,0},{0,-1},{1,0},{0,1}
        };
        while(!q.empty()){
            i=q.front().first;
            j=q.front().second;
            q.pop();
            for(int x=0;x<v.size();x++){
                int row=v[x].first,col=v[x].second;
                row+=i;col+=j;
                if(row>=0 && col >=0 && row<grid.size() && col<grid[0].size()
                && grid[row][col]=='1' && !vis[row][col]){
                    q.push({row,col});
                    vis[row][col]=true;
                }
            }
        }
    }
};
