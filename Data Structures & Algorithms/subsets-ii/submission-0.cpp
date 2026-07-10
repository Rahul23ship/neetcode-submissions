class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>subset;
        vector<int>temp;
        track(subset,nums,temp,0);
        return subset;
    }
    void track(vector<vector<int>>&subset,vector<int>&nums,vector<int>&temp,int i){
        if(i==nums.size()){
            subset.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        track(subset,nums,temp,i+1);
        temp.pop_back();
        while(i+1 < nums.size() && nums[i]==nums[i+1])i++;
        track(subset,nums,temp,i+1);
    }
};
