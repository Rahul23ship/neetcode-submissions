class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        create(ans,n,0,0,"");
        return ans;
    }
    void create(vector<string>&ans,int n, int i,int j,string s){
        if(j>i)return;
        if(i==n){
            while(j<n){
                s+=")";
                j++;
            }
            ans.push_back(s);
            return;
        }

        create(ans,n,i+1,j,s+"(");
        create(ans,n,i,j+1,s+")");
    }
};
