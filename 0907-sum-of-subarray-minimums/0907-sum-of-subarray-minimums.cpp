class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        const long long MOD=1e9+7;
        vector<int>left(n);
        vector<int>right(n);
        stack<int>st;
        for(int i=0;i<n;i++){    //previous smaller element PSE
        while(!st.empty()&&arr[st.top()]>arr[i]){
            st.pop();

        }
        if(st.empty())
            left[i]=-1;
        else
           left[i]=st.top();

          st.push(i);
        } 
        while(!st.empty()){
            st.pop();
        }
// next smaller element   NSE

       for(int i=n-1;i>=0;i--){
        while(!st.empty()&& arr[st.top()]>=arr[i]){
        st.pop();
        }
        if(st.empty())
         right[i]=n;
       else
         right[i]=st.top();
         st.push(i);

     }
      long long ans=0;
      for(int i=0;i<n;i++){
        long long leftchoice=i-left[i];
        long long rightchoice=right[i]-i;  //next smallest  index - current smallest index
        long long contribution=1LL*arr[i]*leftchoice*rightchoice;
        ans=(ans+contribution)%MOD;
      }
return ans;
    }
};