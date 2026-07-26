class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};
        for(char ch: t){
            hash[ch]++;
        }

        int wind = t.length();
        int l = 0;
        int r = 0;
        int sIndex = -1;
        int cnt = 0;
        int minLen = INT_MAX;

        while(r < s.length()){
           if(hash[s[r]] > 0) cnt++;
           hash[s[r]]--;

            while(cnt == wind){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sIndex = l;
                }

                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }

            r++;
        }

        if(sIndex == -1) return "";

        return s.substr(sIndex, minLen);
    }
};
