class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        bool ans;
        vector<int>vis(n,0);
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        ans=check(mp,vis,0,-1);
        for(int i:vis){
            if(i==0)return false;
        }
        return ans;

    }
    bool check(unordered_map<int,vector<int>>&mp,vector<int>&vis,int i,int prev){
        if(vis[i])return false;
        vis[i]=1;
        for(int j:mp[i]){
            if(j==prev)continue;
            if(!check(mp,vis,j,i))return false;
        }
        return true;
    }
};
