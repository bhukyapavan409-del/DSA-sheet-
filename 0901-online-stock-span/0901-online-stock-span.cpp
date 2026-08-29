class StockSpanner {
public:
  stack<pair<int,int>>st;
  int indx;
    StockSpanner() {
        indx=-1;
        
    }
    
    int next(int price) {
        indx++;
        while(!st.empty()&& st.top().first<=price)
         st.pop();
         int ans=indx-(st.empty()?-1:st.top().second);
         st.push({price,indx});
         return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */