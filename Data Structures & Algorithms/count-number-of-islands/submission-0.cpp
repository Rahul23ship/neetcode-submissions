class Solution {
public:
struct pair_hash{
        size_t operator()(const pair<int,int>&p) const{
            return hash<int>()(p.first)^ (hash<int>()(p.second)<<1);
        }
    };
    int numIslands(vector<vector<char>>& grid) {
        unordered_set<pair<int,int>,pair_hash>vis;
        int island=0;
        int row=grid.size(),col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1' && !vis.contains({i,j})){
                    bfs(grid,vis,i,j);
                    island++;
                }
            }
        }
        return island;
    }
    
    void bfs(vector<vector<char>>&grid,unordered_set<pair<int,int>,pair_hash>&vis,int i,int j){
        queue<pair<int,int>>q;
        vis.insert({i,j});
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
                && grid[row][col]=='1' && !vis.contains({row,col})){
                    q.push({row,col});
                    vis.insert({row,col});
                }
            }
        }
    }
};
