class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start^goal;  //XOR 
        int cnt=0;  // count no of set bits in ans
        for(int i=0;i<31;i++){
            if(ans&(1<<i)){   //left sift 
                cnt++;

            }
        }
        return cnt;
    }
};