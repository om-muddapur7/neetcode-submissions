class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();

        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }

        for(auto it: m){
            if(it.second > 1) return true;
        }

        return false;
    }
};