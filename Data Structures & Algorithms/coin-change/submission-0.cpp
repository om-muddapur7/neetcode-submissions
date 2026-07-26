class Solution {
public:

    int f(int idx, vector<int>& coins, int amt, vector<vector<int>>& dp){
        if(idx == 0){
            if(amt % coins[0] == 0) return amt / coins[idx];
            else return 1e9;
        }

        if(dp[idx][amt] != -1) return dp[idx][amt];

        int notTake = 0 + f(idx-1, coins, amt, dp);
        int take = 1e9;
        if(coins[idx] <= amt){
            take = 1 + f(idx, coins, amt-coins[idx], dp);
        }

        return dp[idx][amt] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int res = f(n-1, coins, amount, dp);
        return (res >= 1e9) ? -1 : res;
    }
};
