class Solution {
public:

    void helper(int idx, vector<int>& nums, vector<vector<int>>& res, vector<int>& ds){
        if(idx == nums.size()) {
            res.push_back(ds);
            return;
        }

        ds.push_back(nums[idx]);
        helper(idx+1, nums, res, ds);

        ds.pop_back();
        int i = idx + 1;
        while(i<nums.size() && nums[i] == nums[i-1]) i++;
        helper(i, nums, res, ds);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        helper(0, nums, res, ds);
        return res;
    }
};
