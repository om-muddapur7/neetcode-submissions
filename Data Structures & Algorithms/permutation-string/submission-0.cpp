class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        int m=s1.size();
        int n=s2.size();

        for(char c: s1){
            freq1[c-'a']++;
        }

        for(int r=0; r<n; r++){
            freq2[s2[r]-'a']++;

            if(r>=m){
                freq2[s2[r-m]-'a']--;
            }

            if(freq1==freq2) return true;
        }

        return false;
    }
};
