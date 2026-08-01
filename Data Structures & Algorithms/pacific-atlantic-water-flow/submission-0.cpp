class Solution {
public:
    vector<vector<int>>dir={{0,-1},{0,1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>& heights,int i,int j,int prevh,vector<vector<bool>>&vis){
        if(i<0 || i>=heights.size() || j<0 || j>=heights[0].size() || heights[i][j]<prevh || vis[i][j])return;
        vis[i][j]=true;
        for(auto &d:dir){
            int i_ =i+d[0];
            int j_ =j+d[1];
            dfs(heights,i_,j_,heights[i][j],vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>>result;
        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        vector<vector<bool>>atlantic(n,vector<bool>(m,false));
        for(int i=0;i<m;i++){
            dfs(heights,0,i,INT_MIN,pacific);
            dfs(heights,n-1,i,INT_MIN,atlantic);
        }
        for(int i=0;i<n;i++){
            dfs(heights,i,0,INT_MIN,pacific);
            dfs(heights,i,m-1,INT_MIN,atlantic);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]) result.push_back({i,j});
            }
        }
        return result;
    }
};
