class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,ans=0;
        for(int r=1;r<prices.size();r++){
            int sell=0;
            if(prices[r]<prices[l])l=r;
            else{
                sell=prices[r]-prices[l];
            }
            ans=max(ans,sell);

        }
        return ans;
    }
};
