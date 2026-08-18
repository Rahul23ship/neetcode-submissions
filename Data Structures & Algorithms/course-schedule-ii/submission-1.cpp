class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& p){
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<p.size();i++){
            adj[p[i][0]].push_back(p[i][1]);
        }
        unordered_map<int,int>mp;
        vector<int>ans;
        unordered_set<int>seen;
        bool flag=true;
        for(int i=0;i<adj.size();i++){
            mp[i]++;
            if(!dfs(adj,i,mp,ans,seen))return {};
            if(seen.insert(i).second)ans.push_back(i);
            mp[i]--;
        }
        return ans;
    }
    bool dfs(vector<vector<int>>&adj,int i,unordered_map<int,int>&mp,vector<int>&ans,unordered_set<int>&seen){
        if(adj[i].empty()){
            if(seen.insert(i).second)ans.push_back(i);
            return true;}
        for(int j:adj[i]){
            if(mp[j]>=1)return false;
            mp[j]++;
            if(!dfs(adj,j,mp,ans,seen))return false;
            if(seen.insert(j).second)ans.push_back(j);
            adj[i].pop_back();
            mp[j]--;
        }
        return true;

    }
};
