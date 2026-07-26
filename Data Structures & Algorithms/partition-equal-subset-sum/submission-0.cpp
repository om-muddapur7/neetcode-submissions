class Solution {
public:

    bool f(vector<int>& nums, int i, int target){
        if(i == nums.size()) return target == 0;
        if(target < 0) return false;

        return f(nums, i+1, target) || f(nums, i+1, target-nums[i]);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n: nums) sum += n;

        if(sum % 2 != 0) return false;

        return f(nums, 0, sum/2);
    }
};
