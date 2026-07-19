class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int>hash;
        int n=s.length();
       int l=0;
       int r=0;
       int maxLen=0;
       while(r<n){
        if(hash.find(s[r])!=hash.end()){
            l=max(l,hash[s[r]]+1);
        }
        int len=r-l+1;
        maxLen=max(maxLen,len);
        hash[s[r]]=r;
        r++;
       }
       return maxLen; 
    }
};