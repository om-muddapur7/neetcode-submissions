class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, maxi=0, len=0;
        int n = s.size();
        vector<int> hash (256,-1);

        while(r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }

            len = r - l + 1;
            maxi = max(maxi, len);

            hash[s[r]] = r;
            r++;
        }

        return maxi;
        
    }
};
