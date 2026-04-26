class MinStack {
public:
    stack<long long>st;
    long long mini;
    MinStack() {
        mini=LLONG_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            mini=val;
            st.push(val);
        }
        else{
            if(val>=mini)st.push(val);
            else{
                st.push(2LL*val-mini);
                mini=val;
            }
        }
    }
    
    void pop() {
        if(st.empty())return;
        long long n=st.top();
        st.pop();
        if(n<mini)mini=(2*mini)-n;
        if(st.empty())mini=LLONG_MAX;
        
    }
    
    int top() {
        if(st.empty())return -1;
        long long n=st.top();
        if(mini<=n)return n;
        return mini;        
    }
    
    int getMin() {
        return mini;
    }
};
