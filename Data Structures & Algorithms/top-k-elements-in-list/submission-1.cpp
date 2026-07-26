class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> m;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        for(int it: nums){
            m[it]++;
        }

        for(auto i=m.begin(); i!=m.end(); i++){
            min_heap.push({i->second, i->first});

            if(min_heap.size() > k) min_heap.pop();
        }

        while(!min_heap.empty()){
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }


        return res;
    }
};
