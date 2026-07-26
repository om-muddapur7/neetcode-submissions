class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>freq(10000, 0);

        for(int it: nums){
            if(freq[it] >= 1) return it;
            freq[it]++;
        }
        return -1;
    }
};
