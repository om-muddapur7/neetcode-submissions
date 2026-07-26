class Solution {
public:

    int f(int idx, vector<int>& nums, vector<int>& dp){
        if(idx == 0) return nums[idx];
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];

        int take = nums[idx] + f(idx-2, nums, dp);
        int notTake = 0 + f(idx-1, nums, dp);

        return dp[idx] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        vector<int> t1, t2;
        int n = nums.size();
        if (n == 1) return nums[0];

        for(int i=0; i<n; i++){
            if(i != 0) t1.push_back(nums[i]);
            if(i != n-1) t2.push_back(nums[i]);
        }

        int x = t1.size();

        vector<int> dp(x, -1), dp2(x, -1);

        return max(f(x-1, t1, dp), f(x-1, t2, dp2));
    }
};
