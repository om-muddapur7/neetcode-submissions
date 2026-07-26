class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        
        for(auto s: strs){
            int freq[26] = {0};
            for(char c: s){
                freq[c - 'a']++;
            }

            string key = to_string(freq[0]);
            for(int i=1; i<26; i++){
                key += ',' + to_string(freq[i]);
            }
            m[key].push_back(s);
        }

        for(auto p: m){
            res.push_back(p.second);
        }

        return res;
    }
};
