class Solution {
    map<int,string>mp={
        {2,"abc"},
        {3,"def"},
        {4,"ghi"},
        {5,"jkl"},
        {6,"mno"},
        {7,"pqrs"},
        {8,"tuv"},
        {9,"wxyz"}
    };
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.empty())return ans; 
        dfs(digits,ans,"",0);
        return ans;
    }
    void dfs(string digits,vector<string>&ans,string s,int i){
        if(i>=digits.size()){
            ans.push_back(s);
            return;
        }
        string temp=mp[digits[i]-'0'];
        for(int j=0;j<temp.size();j++){
            dfs(digits,ans,s+temp[j],i+1);
        }
        return;
    }
};
