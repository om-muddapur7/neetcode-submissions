class Solution {
public:

    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi","jkl",
                                  "mno", "qprs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        helper(0, "", digits);
        return res;
    }

    void helper(int ind, string curstr, string& digits){
        if(digits.size() == curstr.size()){
            res.push_back(curstr);
            return;
        }

        string chars = digitToChar[digits[ind] - '0'];
        for(char c: chars){
            helper(ind+1, curstr+c, digits);
        }
    }
};
