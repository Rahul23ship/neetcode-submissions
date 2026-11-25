class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        int reslen=0;
        int n=s.size();
        int l=0,r=0;
        for(int i=0;i<n;i++){
            int p=i,q=i;
            while(p>=0 && q<n && s[p]==s[q]){
                if((q-p+1) > reslen){
                    reslen=q-p+1;
                    l=p,r=q;
                }
                p--,q++;
            }
            
            p=i,q=i+1;
            while(p>=0 && q<n && s[p]==s[q]){
                if(q-p+1 > reslen){
                    reslen=q-p+1;
                    l=p,r=q;
                }
                p--,q++;
            }

        }
        while(l<=r){
            res+=s[l];
            l++;
        }
        
        return res;
    }
};
