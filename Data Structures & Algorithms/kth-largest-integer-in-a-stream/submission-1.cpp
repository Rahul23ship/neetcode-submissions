class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int ki;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(pq.size()>k)pq.pop();
        ki=k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>ki)
        pq.pop();
        return pq.top();

    }
};
