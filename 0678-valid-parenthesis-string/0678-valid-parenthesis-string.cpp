class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        int min=0;
        int max=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                min=min+1;
                max=max+1;
            }
            else if(s[i]==')'){
                min=min-1;
                max=max-1;
            }
            else{     // if  * comes min will always be decreasing  and max is increasing 
                min=min-1;
                max=max+1;
            }
                
                  if(max<0 ){    // starting index is closing bracket
                    return false;
                }
            if(min<0){
                    min=0;
                }
        }
        return (min==0);
    }
};