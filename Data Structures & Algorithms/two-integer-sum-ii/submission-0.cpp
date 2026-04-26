class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        vector<int>ans;
        while(l<r){
            int k=numbers[l]+numbers[r];
            if(k==target){
                ans.push_back(l+1);
                ans.push_back(r+1);
            }
            if(k<target)l++;
            else r--;
        }
        return ans;
    }
};
