class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        double jump=0;
        int left=0;
        int right=0;
        while(right<n-1){
            int maxFar=0;
            for(int i=left;i<=right;i++){
                maxFar=max(i+nums[i],maxFar);
            }
            left=right+1;
            right=maxFar;
            jump=jump+1;
        }
        return jump;
    }
};