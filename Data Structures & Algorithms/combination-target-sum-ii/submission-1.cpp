class Solution {
public:

    void helper(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& ds, int i) {
        if(candidates.size() == i){
            if(target == 0)
                res.push_back(ds);
            return;
        }

        if(candidates[i] <= target){
            ds.push_back(candidates[i]);
            helper(candidates, target-candidates[i], res, ds, i+1);
            ds.pop_back();
        }

        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }

        helper(candidates, target, res, ds, i+1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;

        sort(candidates.begin(), candidates.end());

        helper(candidates, target, res, ds, 0);
        return res;
    }
};
