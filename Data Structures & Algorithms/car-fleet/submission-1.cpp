class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>mp;
        for(int i=0;i<position.size();i++){
            double time=(double)(target-position[i])/speed[i];
            mp.push_back({position[i],time});
        }
        sort(mp.rbegin(),mp.rend());
        stack<double>st;
        for(auto& p:mp){
            double ctime=p.second;
            if(st.empty() || ctime>st.top())st.push(ctime);

        }
        return st.size();
    }
};
