class Solution {
public:
    bool isPalindrome(string s) {
        int left=0,right=s.size()-1;
        bool ans=true;
        while(left<right){
            if(!isalnum(s[left])){left++;continue;}
            if(!isalnum(s[right])){right--;continue;}
            if(tolower(s[left])!=tolower(s[right])){
                ans=false;
                break;
            }
            left++;
            right--;
        }
        return ans;
    }
};
