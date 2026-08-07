class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        
        helper(nums, res, subset, 0, target);

        return res;
    }

    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& subset, int i, int target){
        if(nums.size() == i){
            if(target == 0){
                res.push_back(subset);
            }
            return;
        }

        if(nums[i] <= target){
            subset.push_back(nums[i]);
            helper(nums, res, subset, i, target-nums[i]);

            subset.pop_back();
        }
        
        helper(nums, res, subset, i+1, target);
    }

};
