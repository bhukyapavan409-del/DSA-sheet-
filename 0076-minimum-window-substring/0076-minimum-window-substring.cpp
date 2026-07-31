class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> map(256, 0);

        for (int i = 0; i < m; i++)
            map[t[i]]++;

        int l = 0, r = 0;
        int minlen = INT_MAX;
        int stidx = -1;
        int cnt = 0;

        while (r < n) {

            if (map[s[r]] > 0)
                cnt++;

            map[s[r]]--;

            while (cnt == m) {

                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    stidx = l;
                }

                map[s[l]]++;

                if (map[s[l]] > 0)
                    cnt--;

                l++;
            }

            r++;
        }

        return stidx == -1 ? "" : s.substr(stidx, minlen);
    }
};