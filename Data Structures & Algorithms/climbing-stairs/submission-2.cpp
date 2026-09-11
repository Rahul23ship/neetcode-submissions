class Solution {
public:
    int climbStairs(int n) {
        vector<int>v(n+1,-1);
        climb(n,v);
        return v[n];

    }
    int climb(int i,vector<int>&v){
        if(i<=1)return v[i]=1;
        if(v[i]!=-1)return v[i];
        return v[i]=climb(i-1,v)+climb(i-2,v);
    }
};
