class Solution {
public:

    int f(int ind, int prev, int n, vector<int>& nums){
        if(ind == n) return 0;

        int len = 0 + f(ind+1, prev, n, nums);
        if(prev == -1 || nums[ind] > nums[prev]){
            len = max(len, 1 + f(ind+1, ind, n, nums));
        }

        return len;
    }

    int lengthOfLIS(vector<int>& nums) {
        return f(0, -1, nums.size(), nums);
    }
};
