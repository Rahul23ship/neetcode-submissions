class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;
        dfs(res,temp,s,0);
        return res;
    }
    void dfs(vector<vector<string>>&res,vector<string>&temp,string s,int i){
        if(i>=s.size()){
            res.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(isPall(s,i,j)){
                temp.push_back(s.substr(i,(j-i+1)));
                dfs(res,temp,s,j+1);
                temp.pop_back();
            }
        }
        return;
    }
    bool isPall(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
};
