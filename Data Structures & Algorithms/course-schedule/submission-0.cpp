class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build the graph
        vector<vector<int>> graph(numCourses);
        for (auto &pre : prerequisites) {
            int course = pre[0], prereq = pre[1];
            graph[prereq].push_back(course); // prereq -> course
        }

        // Step 2: Visited array for cycle detection
        vector<int> visited(numCourses, 0);

        // Step 3: DFS function
        function<bool(int)> dfs = [&](int node) {
            if (visited[node] == 1) return false; // cycle detected
            if (visited[node] == 2) return true;  // already safe

            visited[node] = 1; // mark as visiting
            for (int next : graph[node]) {
                if (!dfs(next)) return false;
            }
            visited[node] = 2; // mark as safe
            return true;
        };

        // Step 4: Check each course
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) return false;
        }
        return true;
    }
};
