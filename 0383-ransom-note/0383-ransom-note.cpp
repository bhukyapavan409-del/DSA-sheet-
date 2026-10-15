class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26]={0};
        for(char c:magazine){
            freq[c-'a']++;  //freq[c-'a'] stores count of the characters
        }               
        for(char c:ransomNote){
            freq[c-'a']--;

            if(freq[c-'a']<0){  // if it return -1 then the character is not present 
                return false;
            }
        }
        return true;
    }
};