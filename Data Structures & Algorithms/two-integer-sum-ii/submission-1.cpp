class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int n = num.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j && num[i]+num[j] == target)
                    return {i+1, j+1};
            }
        }
        return {};
    }
};
