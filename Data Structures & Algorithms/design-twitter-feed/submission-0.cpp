class Twitter {
public:
    int timer;
    unordered_map<int,vector<pair<int,int>>>tweets;
    unordered_map<int,unordered_set<int>>follower;
    struct Node{
        int time;
        int tweetid;
        int userid;
        int ind;
        Node(int t,int tw,int uw,int i){
            time=t;
            tweetid=tw;
            userid=uw;
            ind=i;
        }
    };
    struct cmp{
        bool operator()(Node &a,Node &b){
            return a.time<b.time;
        }
    };
    Twitter() {
        timer=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++,tweetId});  
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Node,vector<Node>,cmp>pq;
        if(!tweets[userId].empty()){
            int idx=tweets[userId].size()-1;
            pq.push(Node(tweets[userId][idx].first,
            tweets[userId][idx].second,
            userId,
            idx));
        }

        for(int followee:follower[userId]){
            if(!tweets[followee].empty()){
                int idx=tweets[followee].size()-1;
                pq.push(Node(tweets[followee][idx].first,
                tweets[followee][idx].second,
                followee,
                idx));
            }
        }
        vector<int>ans;
        while(!pq.empty() && ans.size()<10){
            Node curr=pq.top();
            pq.pop();
            ans.push_back(curr.tweetid);
            if(curr.ind>0){
                int prev=curr.ind-1;
                pq.push(Node(tweets[curr.userid][prev].first,
                    tweets[curr.userid][prev].second,
                    curr.userid,
                    prev
                ));
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId)return;
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};
