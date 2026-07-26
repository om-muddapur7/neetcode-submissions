class Solution {
public:

    int f(int ind, vector<int>& prices, int buy){
        if(ind >= prices.size()) return 0;

        int profit = 0;

        if(buy){
            profit = max((-prices[ind] + f(ind+1, prices, 0)),
                        (0 + f(ind+1, prices, 1)));
        }
        else{
            profit = max((+prices[ind] + f(ind+2, prices, 1)),
                        (0 + f(ind+1, prices, 0)));
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        return f(0, prices, 1);
    }
};
