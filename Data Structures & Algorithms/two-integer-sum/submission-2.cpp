class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> m;

        for(int i=0; i<nums.size(); i++){
            int first = nums[i];
            int second = target - first;

            if(m.find(second) != m.end()){
                
                res.push_back(m[second]);
                res.push_back(i);

                break;
            }

            m[first] = i;
        }

        return res;
        
    }
};
