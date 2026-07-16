class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxIndx=0;
        for(int i=0;i<=n-1;i++){
            if(i>maxIndx){
                return false;
            }
            maxIndx=max(maxIndx,i+nums[i]);
        }
        return true;
    }
};