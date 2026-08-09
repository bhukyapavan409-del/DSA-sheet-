class Solution {
public:
    int repeatedStringMatch(string a, string b) {

        int n = a.length();
        int m = b.length();

        int k = (m + n - 1) / n;

        string s = "";

                      // k is no of repetions 
        for (int i = 0; i < k; i++) {
            s += a;
        }

       
        if (s.find(b) != string::npos) {
            return k;
        }

        
        s += a;

        if (s.find(b) != string::npos) {
            return k + 1;
        }

        return -1;
    }
};