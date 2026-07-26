class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);

        for(auto it: prerequisites){
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }

        queue<int>q;
        vector<int> res;
        res.reserve(n);

        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int finish = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            finish++;
            res.push_back(node);

            for(auto neigh: adj[node]){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }  
        }

        if(finish != n) return {};

        return res;
    }
};
