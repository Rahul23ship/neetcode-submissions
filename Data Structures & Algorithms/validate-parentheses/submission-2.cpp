class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        if(n&1)return false;
        stack<char>st;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='('||c=='{'||c=='['){
                st.push(c);
            }
            else{
                if(st.empty())return false;
                char ch=st.top();st.pop();
                if((ch=='{' && c!='}')||(ch=='(' && c!=')')||(ch=='[' && c!=']'))return false;
            }
        }
        return st.empty();
    }
};
