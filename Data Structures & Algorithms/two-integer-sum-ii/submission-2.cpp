class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;

        for(int i=0; i<numbers.size(); i++){
            for(int j=0; j<numbers.size(); j++){
                if(i!=j && numbers[i]+numbers[j] == target){
                    res.push_back(i+1);
                    res.push_back(j+1);
                    return res;
                }
            }
        }

        return res;
    }
};
