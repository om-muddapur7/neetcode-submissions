class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m; //num,cnt
        vector<int> res;

        for(int n: nums){
            m[n]++;
        }

        vector<pair<int, int>> sr;
        for(auto i: m){
            sr.push_back({i.second, i.first});
        }

        sort(sr.rbegin(), sr.rend());

        for(int i=0; i<k; i++){
            res.push_back(sr[i].second);
        }

        return res;
    }
};
