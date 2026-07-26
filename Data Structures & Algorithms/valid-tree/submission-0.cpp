class Solution {
public:

    bool dfs(int node, int prev, vector<vector<int>>& adj, vector<bool>& vis){
        vis[node] = 1;

        for(auto neigh: adj[node]){
            if(neigh == prev) continue;
            if(vis[neigh]) return false;
            if(!dfs(neigh, node, adj, vis)) return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) { 
        if(edges.size() != n-1) return false;
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        if(!dfs(0, -1, adj, vis)) return false;

        for(bool v: vis){
            if(!v) return false;
        }

        return true;
    }
};
