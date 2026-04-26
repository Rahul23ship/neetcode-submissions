class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>v(nums.size(),0);
        int n=nums.size();
        int prefix=1;
        for(int i=0;i<n;i++){
            v[i]=prefix;
            prefix*=nums[i];
        }
        int suffix=1;
        for(int i=n-1;i>=0;i--){
            v[i]*=suffix;
            suffix*=nums[i];
        }
        return v;
    }
};
