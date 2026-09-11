class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>v(n+1,-1);
        climb(0,cost,v);
        return min(v[0],v[1]);
    }
    int climb(int i,vector<int>&cost,vector<int>&v){
        if(i>=cost.size())return 0;
        if(i==cost.size()-1)return v[i]=cost[i];
        if(v[i]!=-1)return v[i];
        return v[i]=cost[i]+min(climb(i+1,cost,v),climb(i+2,cost,v));
    }
};
