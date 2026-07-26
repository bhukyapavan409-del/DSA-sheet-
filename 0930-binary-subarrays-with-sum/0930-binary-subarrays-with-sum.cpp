class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ans = 0;
        int i = 0;
        int j = 0;
        int currSum = 0;
        int count_zero = 0;

        while (j < n) {
            currSum += nums[j];

            
            while(i< j && (nums[i] == 0 || currSum > goal)){
                if(nums[i] == 0) count_zero++;
                else count_zero = 0;

                currSum -= nums[i];
                i++;
            }
             if(currSum == goal){
                ans += 1 + count_zero;

            }
             j++;
        }
        return ans;
    }
};