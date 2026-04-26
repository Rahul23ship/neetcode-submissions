class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int l=0;
        unordered_map<char,pair<int,int>>mp;
        for(int r=0;r<s.size();r++){
            if(mp[s[r]].first==0){
                mp[s[r]].first++;    
            }
            else{
                if(l<=mp[s[r]].second)l=mp[s[r]].second+1;      
            }
            mp[s[r]].second=r;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
