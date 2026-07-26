class Solution {
public:

    void helper(int idx, vector<int>& arr, int target, vector<vector<int>>& res, vector<int>& ds ){
            if(target == 0){
                res.push_back(ds);
                return;
            }

        for(int i=idx; i<arr.size(); i++){
            if(i > idx &&  arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            helper(i+1, arr, target-arr[i], res, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> ds;
        helper(0, candidates, target, res, ds);
        return res;
    }
};
