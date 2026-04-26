class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int r=*max_element(piles.begin(),piles.end());
        int l=1;
        int mini=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            long long time=0;
            for(int i=0;i<n;i++){
                time+=(1LL*piles[i]+mid-1)/mid;
            }
            if(time>h)l=mid+1;
            else{
                r=mid-1;
                mini=mid;
            } 
        }
        return mini;
    }
};
