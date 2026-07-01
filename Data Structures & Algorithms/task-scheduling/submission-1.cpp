class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(int i=0;i<tasks.size();i++)mp[tasks[i]]++;
        priority_queue<int>pq;
        for(auto &it:mp){
            pq.push(it.second);
        }
        int time=0;
        queue<pair<int,int>>q;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
                int count=pq.top()-1;
                pq.pop();
                if(count){
                    q.push({count,time+n});
                }
            }
            if(!q.empty() && q.front().second==time){
                int temp=q.front().first;
                q.pop();
                pq.push(temp);
            }
        }
        return time;
    }
};
