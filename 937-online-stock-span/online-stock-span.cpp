class StockSpanner {
    vector<int> ranges;
    vector<int> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        ranges.push_back(price);
        while (!st.empty() && ranges[st.back()] <= price) st.pop_back();
        int n = ranges.size();
        int res = (!st.empty())? n-st.back() -1: n;
        st.push_back(n-1);

        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */