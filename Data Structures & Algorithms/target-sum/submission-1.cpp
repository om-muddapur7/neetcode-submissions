class Solution {
public:

    int f(int ind, int total, vector<int>& nums, int target){
        if(ind == nums.size()){
            if(total == target) return 1;
            return 0;
        }

        int neg = f(ind+1, total-nums[ind], nums, target);
        int pos = f(ind+1, total+nums[ind], nums, target);

        return neg+pos;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return f(0, 0, nums, target);
    }
};
