class Solution {
public:
    int fun(vector<int>& arr){
        int n=arr.size();
        int prev1=arr[0],prev2=0;
        for(int i=1;i<n;i++){
            int take=arr[i]+prev2;
            int not_take=0+prev1;
            int curr=max(take,not_take);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;

    }
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        if(nums.size()<1)return 0;
        if(nums.size()==1)return nums[0];
        for (int i=0;i<nums.size();i++){
            if(i!=0)temp2.push_back(nums[i]);
            if(i!=nums.size()-1)temp1.push_back(nums[i]);
        }
        return max(fun(temp1),fun(temp2));
    }
};
