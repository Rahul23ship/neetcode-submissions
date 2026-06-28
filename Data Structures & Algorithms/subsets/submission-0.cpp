class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int> sub;
        ans(v,nums,sub,0);
        return v;
    }
    void ans(vector<vector<int>>&v,vector<int>&nums,vector<int>& sub,int i){
        if(i>=nums.size()){
            v.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        ans(v,nums,sub,i+1);
        sub.pop_back();
        ans(v,nums,sub,i+1);
        return;
    }
};
