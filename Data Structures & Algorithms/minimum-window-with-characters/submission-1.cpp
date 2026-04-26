class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size()<t.size()|| t=="") return "";
        unordered_map<char,int>win,count;
        for(int i=0;i<t.size();i++){
            count[t[i]]++;
        }
        int li=-1, ri=-1,mini=INT_MAX,l=0,have=0,need=count.size();
        for(int r=0;r<s.size();r++){
            win[s[r]]++;
            if(win[s[r]]==count[s[r]]){
                have++;
            }
            while(have==need){
                if (mini>r-l+1){
                    li=l;ri=r;mini=r-l+1;
                }
                win[s[l]]--;
                if(win[s[l]]<count[s[l]])have--;
                l++;
            }
        }
        string ans="";
        for(int i=li;i<(ri+1);i++){
            ans+=s[i];
        }
        if(mini==INT_MAX)return "";
        return ans;
    }
};
