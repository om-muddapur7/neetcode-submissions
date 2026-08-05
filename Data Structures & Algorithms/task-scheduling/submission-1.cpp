class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cpu = 0;
        priority_queue<int> pq;

        vector<int> mp(26, 0);
        for(int i=0; i<tasks.size(); i++){
            mp[tasks[i] - 'A']++;
        }

        for(int it: mp){
            if(it > 0) pq.push(it);
        }

        while(!pq.empty()){
            vector<int> temp;

            for(int i = 0; i <= n && !pq.empty(); i++){
                int freq = pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
            }

            for(int it: temp){
                if(it > 0) pq.push(it);
            }

            if(pq.empty()) cpu += temp.size();
            else cpu += n+1;
        }

        return cpu;
    }
};
