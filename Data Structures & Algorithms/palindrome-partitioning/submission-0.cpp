class Solution {
public:

    bool isPalindrome(string s, int st, int end){
        while(st <= end){
            if(s[st++] != s[end--]){
                return false;
            }
        }
        return true;
    }

    void helper(int ind, string s, vector<vector<string>>& res, vector<string>& ds){
        if(ind == s.size()){
            res.push_back(ds);
            return;
        }

        for(int i=ind; i<s.size(); i++){
            if(isPalindrome(s, ind, i)){
                ds.push_back(s.substr(ind, i-ind+1));
                helper(i+1, s, res, ds);
                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ds;
        helper(0, s, res, ds);
        return res;
    }
};
