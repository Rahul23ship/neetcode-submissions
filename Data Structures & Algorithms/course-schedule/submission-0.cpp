class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {\
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<p.size();i++){
            adj[p[i][0]].push_back(p[i][1]);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<adj.size();i++){
            mp[i]++;
            if(!dfs(adj,i,mp))return false;
            mp[i]--;
        }
        return true;

    }
    bool dfs(vector<vector<int>>&adj,int i,unordered_map<int,int>&mp){
        if(adj[i].empty())return true;
        for(int j:adj[i]){
            if(mp[j]>=1)return false;
            mp[j]++;
            if(!dfs(adj,j,mp))return false;
            adj[i].pop_back();
            mp[j]--;
        }
        return true;

    }
};
