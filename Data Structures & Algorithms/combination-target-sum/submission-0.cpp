class Solution {
public:

    void helper(int idx, vector<int>& nums, int target, vector<vector<int>>& res,vector<int>& ds){
        if(idx == nums.size()){
            if(target == 0){
                res.push_back(ds);
            }
            return;
        }

        if(nums[idx] <= target){
            ds.push_back(nums[idx]);
            helper(idx, nums, target-nums[idx], res, ds);
            ds.pop_back();
        }
        helper(idx+1, nums, target, res, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        helper(0, nums, target, res, ds);
        return res;
    }
};
