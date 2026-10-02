class StockSpanner {
public:
    stack<pair<int, int>> st; // {val, ind}
    int ind;
    StockSpanner() {
         ind=-1;
    }
    
    int next(int val) {
        ind+=1;
        while (!st.empty() && st.top().first <= val) {
            st.pop();
        }
        int ans=ind-(st.empty() ? -1 : st.top().second);

        st.push({val, ind});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */