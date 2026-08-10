class Solution {
public:

    bool isPalin(string s){
        string t = s;
        reverse(t.begin(), t.end());

        return t == s;
    }

    void getAllParts (string s, vector<vector<string>>& ans, vector<string> &ds){
        if(s.size() == 0){
            ans.push_back(ds);
            return;
        }

        for(int i=0; i<s.size(); i++){
            string part = s.substr(0, i+1);

            if(isPalin(part)){
                ds.push_back(part);
                getAllParts(s.substr(i+1), ans, ds);
                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;

        getAllParts(s, ans, ds);
        return ans;
    }
};
