class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        res(ans,nums,0);
        return ans;
    }
    void res(vector<vector<int>>&ans,vector<int>&nums,int i){
        if(i==nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            res(ans,nums,i+1);
            swap(nums[i],nums[j]);
        }
        return;
        
        
    }
};
