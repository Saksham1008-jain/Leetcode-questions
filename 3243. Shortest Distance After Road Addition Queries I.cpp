class Solution {

private:
    int solve(int n, const unordered_map<int, vector<int>>& adj) {
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int nd = q.front();
            q.pop();

            if (adj.find(nd) != adj.end()) {
                for (int nbr : adj.at(nd)) {
                    if (dist[nbr] == INT_MAX) {
                        dist[nbr] = dist[nd] + 1;
                        q.push(nbr);
                    }
                }
            }
        }
        if(dist[n-1]==INT_MAX){
            return -1;
        }
        return dist[n-1];
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n - 1; ++i) {
            adj[i].push_back(i + 1);
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            adj[u].push_back(v);

            int t = solve(n, adj);
            ans[i] = t;
        }

        return ans;
    }
};

