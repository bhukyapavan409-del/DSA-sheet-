class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int close=0;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='('){
                open++;
            }
            else{
                if(open<=0){    // if empty 
                    close++;
                }
                else{
                    open--;
                }
            }
        }
        return (open+close);
    }
};