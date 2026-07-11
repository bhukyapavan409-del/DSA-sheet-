class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor){   //both equal
            return 1;
        }
        bool sign=true;
        if(dividend>=0 && divisor<0) sign=false;
        else if(dividend<0 && divisor>0) sign=false;
      long long n=abs((long long)dividend);
    long long d=abs((long long)divisor);
        long long ans=0;
        while(n>=d){
            int cnt=0;
            while(n>=(d<<(cnt+1))){    // d * 2**cnt+1
                cnt++;
            }
            ans+=(1<<cnt); // 2**cnt
            n=n-(d<< cnt);  //  d*2**cnt
        }
  if(ans==(1<<31) && sign==true){
    return INT_MAX;
  }
  if(ans==(1<<31) && sign==false){
    return INT_MIN;

  }
     return sign?ans:(-1*ans);
    }
};