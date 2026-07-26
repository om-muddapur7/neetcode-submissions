class Solution {
public:

    bool checkFreq(int freq1[], int freq2[]){
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};

        for(char ch: s1){
            freq[ch - 'a']++;
        }

        int window = s1.length();

        for(int j=0; j<s2.length(); j++){
            int windSize = 0;
            int idx = j;
            int windfreq[26] = {0};

            while(windSize < window && idx < s2.length()){
                windfreq[s2[idx] - 'a']++;
                idx++;
                windSize++;
            }

            if(checkFreq(freq, windfreq)) return true;
        }

        return false;
    }
};
