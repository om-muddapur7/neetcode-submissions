class Solution {
public:

    vector<string> res;

    void solve(string digits, vector<string> mp, string cur, int idx){
        if(idx == digits.size()){
            res.push_back(cur);
            return;
        }

        string letters = mp[digits[idx] - '0'];

        for(char ch: letters){
            solve(digits, mp, cur + ch, idx+1);
        }
    }

    vector<string> letterCombinations(string digits) {
         if(digits.empty()) return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        solve(digits, mp, "", 0);
        return res;
    }
};
