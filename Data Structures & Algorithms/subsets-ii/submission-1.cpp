class Solution {
public:

    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& ds, int i) {
        if(i == nums.size()){
            res.push_back(ds);
            return;
        }

        ds.push_back(nums[i]);
        helper(nums, res, ds, i+1);

        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;

        ds.pop_back();
        helper(nums, res, ds, i+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;

        sort(nums.begin(), nums.end());

        helper(nums, res, ds, 0);

        return res;
    }
};
