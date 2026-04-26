class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>v;
        for(int i=0;i<nums.size();i++){
           int l=i+1,r=nums.size()-1;
           while(l<r){
            int Sum=nums[i]+nums[l]+nums[r];
            if(Sum==0){
                v.insert({nums[i],nums[l],nums[r]});
                l++;
                r--;
            }
            else if(Sum>0)r--;
            else l++;
           }
        }
        vector<vector<int>>ans;
        for(auto &it:v){
            ans.push_back(it);
        }
        return ans;
    }
};
