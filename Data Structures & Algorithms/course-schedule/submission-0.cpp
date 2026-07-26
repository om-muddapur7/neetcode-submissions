class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);

        for(auto it: prerequisites){
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }

        queue<int> q;
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

            for(int neigh: adj[node]){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        return finish == n;
    }
};
