class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp=0;
        int best = prices[0];

        for(int i=1; i<prices.size(); i++){
            if(prices[i]>best){
                maxp= max(maxp, prices[i]-best);
            }
            best = min(best, prices[i]);
        }
        return maxp;
    }
};
