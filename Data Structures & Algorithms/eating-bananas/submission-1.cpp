class Solution {
public:

    int func(vector<int>& piles, int mid){
        int sum = 0;

        for(int i=0; i<piles.size(); i++){
            sum += ceil((double)piles[i] / mid);
        }

        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1;
        int end = 0;

        for(int i=0; i<piles.size(); i++){
            end = max(end, piles[i]);
        }

        int ans = INT_MAX;

        while(st <= end){
            int mid = (st + end)/2;

            int totalhrs = func(piles, mid);

            if(totalhrs <= h){
                end = mid - 1;
                ans = min(ans, mid);
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }
};
