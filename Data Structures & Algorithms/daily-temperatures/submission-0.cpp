class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>>st;
        vector<int>ans(temp.size(),0);
        st.push({temp[0],0});
        for(int i=1;i<temp.size();i++){
            while(!st.empty() && temp[i]>st.top().first){
                int a=st.top().first,ind=st.top().second;
                st.pop();
                ans[ind]=i-ind;

            }
            st.push({temp[i],i});
        }
        return ans;
        
    }
};
