class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())return false;
        unordered_map<char,int>mp,mp1;
        for(int i=0;i<s1.size();i++){
            mp[s1[i]]++;
            mp1[s2[i]]++;
        }
        int match=0;
        for(char i='a';i<='z';i++){
            if(mp[i]==mp1[i])match++;
        }
        int l=0;
        for(int r=s1.size();r<s2.size();r++){
            if(match==26)return true;

            char in=s2[r],out=s2[l];
            mp1[in]++;
            if(mp[in]==mp1[in])match++;
            else if(mp[in]+1==mp1[in])match--;

            mp1[out]--;
            if(mp[out]==mp1[out])match++;
            else if(mp[out]-1==mp1[out])match--;
            l++;
        }

        return match==26;
    }
};
