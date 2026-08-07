class Solution {
public:

    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& subset, int i){
        if(nums.size() == i){
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        helper(nums, res, subset, i+1);

        subset.pop_back();
        helper(nums, res, subset, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        
        helper(nums, res, subset, 0);

        return res;
    }
};
