class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>parent(n);
        iota(parent.begin(),parent.end(),0);
        vector<int>rank(n,1);
        int res=n;
        for(auto i:edges){
            res-=(Union(parent,rank,i[0],i[1]));
        }
        return res;
    }
    int Find(vector<int>&p, int i){
        int res=i;
        while(res != p[res]){
            p[res]=p[p[res]];
            res=p[res];
        }
        return res;
    }
    int Union(vector<int>&p,vector<int>&rank,int i,int j){
        int p1=Find(p,i);
        int p2=Find(p,j);
        if(p1==p2)return 0;
        if(rank[p2]>rank[p1]){
            p[p1]=p[p2];
            rank[p2]+=rank[p1];
        }
        else{
            p[p2]=p[p1];
            rank[p1]+=rank[p2];
        }
        return 1;
    }
};
