class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long num = 0;
        vector<int> res;
        for(int it: digits){
            num = num*10 + it;
        }

        num = num + 1;

        if (num == 0) return {0};

        while(num != 0){
            int dig = num % 10;
            res.push_back(dig);
            num /= 10;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
