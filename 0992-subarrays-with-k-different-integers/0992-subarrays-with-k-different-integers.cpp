class Solution {
public:

    int atMostK(vector<int>& nums, int k)
    {
        int count =0, n = nums.size(), l = 0, r = 0, ans = 0;
        unordered_map<int,int> freq;
        int distinct = 0;
        while(r < n)
        {
            freq[nums[r]]++;
            if (freq[nums[r]] == 1) distinct++;
            while(distinct > k)
            {
                freq[nums[l]]--;
                if(freq[nums[l]] == 0) distinct--;
                l++;
            }
            ans += (r-l+1);
            r++;
        }  
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        
        return atMostK(nums, k) - atMostK(nums, k-1);
    }
};