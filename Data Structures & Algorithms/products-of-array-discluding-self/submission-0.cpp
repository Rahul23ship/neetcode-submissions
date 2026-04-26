class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
vector<int>v(nums.size(),0);
        int product=1,countz=0,indexz;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                countz++;
                indexz=i;
                continue;
            }
            product*=nums[i];
        }
        if(countz>1)return v;
        else if(countz==1){
            v[indexz]=product;
            return v;
        }
        else{
            for(int i=0;i<nums.size();i++){
                v[i]=product/(nums[i]);
            }
        }
        return v;
    }
};
