class Solution {
    vector<int>temp;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        sort(candidates.begin(),candidates.end());
        ans(res,candidates,target,0);
        
        return res;
    }
    void ans(vector<vector<int>> &res, vector<int>& candidates,int target,int i){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(i>=candidates.size()|| target<0)return;
        
        temp.push_back(candidates[i]);
        ans(res,candidates,target-candidates[i],i+1);
        temp.pop_back();
        int t=candidates[i];
        while(i<candidates.size() && candidates[i]==t ){
            i++;
        }
        ans(res,candidates,target,i);
        return;
    }
};
