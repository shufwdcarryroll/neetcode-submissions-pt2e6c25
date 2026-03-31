class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false; // must have n-1 edges

        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (int nei : graph[node]) {
                if (!visited[nei]) {
                    dfs(nei);
                }
            }
        };

        dfs(0); // start from node 0

        // check if all nodes visited (connected)
        for (bool v : visited) {
            if (!v) return false;
        }

        return true;
    }
};
