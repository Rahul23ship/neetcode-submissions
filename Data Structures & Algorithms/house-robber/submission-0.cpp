class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n+1,-1);
        climb(0,nums,v);
        climb(1,nums,v);
        return max(v[0],v[1]);
    }
    int climb(int i,vector<int>&nums,vector<int>&v){
        if(i>=nums.size())return 0;
        if(i==nums.size())return v[i]=nums[i];
        if(v[i]!=-1)return v[i];
        return v[i]=nums[i]+max(climb(i+2,nums,v),climb(i+3,nums,v));
    }
};
