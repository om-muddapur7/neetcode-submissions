class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int n = nums.size();
        unordered_map<int, int> m;

        for(int i=0; i<n; i++){
            int diff = target - nums[i];

            if(m.find(diff) != m.end()){
                return {m[diff], i};
            }

            m.insert({nums[i], i});
            
        }
        
        return res;
    }
};
