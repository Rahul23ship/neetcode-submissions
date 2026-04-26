class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=nums.size()-1;
        int mini=INT_MAX;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[r])l=mid+1;
            else r=mid-1;
            mini=min(mini,nums[mid]);
        }
        return mini;
    }
};
