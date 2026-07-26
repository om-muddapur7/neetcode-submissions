class Solution {
public:

    int f(int ind, vector<int>& coins, int amt, vector<vector<int>>& dp){
        if(ind == 0){
            if(amt % coins[0] == 0) return 1;
            return 0;
        }

        if(dp[ind][amt] != -1) return dp[ind][amt];

        int notTake = f(ind-1, coins, amt, dp);
        int take = 0;
        if(coins[ind] <= amt) take = f(ind, coins, amt-coins[ind], dp);

        return dp[ind][amt] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        return f(n-1, coins, amount, dp);
    }
};
