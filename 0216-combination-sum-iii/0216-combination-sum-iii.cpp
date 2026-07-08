class Solution {
public:
    void findCombination(int i,int k,int sum,int n,vector<int>&nums,vector<vector<int>>&ans){
        if(sum>n) return; //exceeds sum
        if(k==0 && sum==n){
            ans.push_back(nums);
            return;

        }
        if(i==10) return;  //1-9
        nums.push_back(i);   //pick
        findCombination(i+1,k-1,sum+i,n,nums,ans);
        nums.pop_back(); // not pick
        findCombination(i+1,k,sum,n,nums,ans);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>ans;
        vector<int>nums;
        findCombination(1,k,0,n,nums,ans);   //index=1 not 0
        return ans;
    }
};