class Solution {
public:

    int helper(int ind, vector<int>& cost){
        if(ind == 0 || ind==1) return 0;

        int left = cost[ind-1] + helper(ind-1, cost);
        int right = cost[ind-2] + helper(ind-2, cost);

        return min(left, right);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return helper(n, cost);
    }
};
