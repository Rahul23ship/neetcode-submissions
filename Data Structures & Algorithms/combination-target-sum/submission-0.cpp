class Solution {
    vector<int>temp;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        combine(ans,nums,target,0,0);
        return ans;
    }

    void combine(vector<vector<int>>& ans,vector<int>&nums,int target,int sum,int i){
        if(i>=nums.size() || sum>target)return;
        
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        combine(ans,nums,target,sum+nums[i],i);
        temp.pop_back();
        combine(ans,nums,target,sum,i+1);
        return;
    }
};
