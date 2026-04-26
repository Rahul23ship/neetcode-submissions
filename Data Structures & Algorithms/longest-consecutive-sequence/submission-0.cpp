class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int maxi=0;
        for(int curr:st){
            if(st.find(curr-1)==st.end()){
                int num=curr;
                int length=1;
                while(st.find(num+1)!=st.end()){
                    num++;
                    length++;
                }
                maxi=max(maxi,length);
            }
            
        }
        return maxi;
    }
};
