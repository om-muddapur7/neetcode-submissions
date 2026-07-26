class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()==0) return 0;

        sort(nums.begin(), nums.end());

        int cnt=1, maxcnt=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] == nums[i]) continue;
            else if(nums[i] == nums[i-1]+1) cnt++;
            else {
                maxcnt=max(maxcnt, cnt);
                cnt=1;
            }
        }
        return maxcnt>cnt ? maxcnt:cnt;
    }
};
