class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        int left=0;;  //cookie index
        int right=0;   //children  index
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(left<m && right<n){
            if(g[right]<=s[left]){
                right=right+1;
            }
            left=left+1;


        }
   return right;
        
    }
};