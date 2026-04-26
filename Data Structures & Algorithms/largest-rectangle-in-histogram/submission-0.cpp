class Solution {
public:
    vector<int> lms(vector<int>&v){
        int n=v.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && v[st.top()]>=v[i]){
                st.pop();
            }
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> rms(vector<int>&v){
        int n=v.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && v[st.top()]>=v[i]){
                st.pop();
            }
            if(st.empty())ans[i]=n;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>ls=lms(heights);
        vector<int>rs=rms(heights);
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            int len=(rs[i]-ls[i]-1)*heights[i];
            maxi=max(maxi,len);
        }
        return maxi;
    }
};
