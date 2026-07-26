class Solution {
public:

    void helper(vector<int>& nums, vector<vector<int>>& res,vector<int>& cur, int i){
        if(nums.size() == i){
            res.push_back(cur);
            return;
        } 

        cur.push_back(nums[i]);
        helper(nums, res,cur, i+1);

        cur.pop_back();
        helper(nums, res,cur, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(nums, res, cur, 0);
        return res;
    }
};
