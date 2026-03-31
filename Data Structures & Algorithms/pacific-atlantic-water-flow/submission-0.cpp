class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> res;
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        // DFS function
        auto dfs = [&](auto&& self, int i, int j, vector<vector<bool>>& visited) -> void {
            visited[i][j] = true;
            int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
            for(auto &d : dirs) {
                int x = i + d[0], y = j + d[1];
                if(x >= 0 && x < m && y >= 0 && y < n 
                   && !visited[x][y] && heights[x][y] >= heights[i][j]) {
                    self(self, x, y, visited);
                }
            }
        };
        
        // Run DFS for Pacific (top & left edges)
        for(int i = 0; i < m; i++) dfs(dfs, i, 0, pacific);
        for(int j = 0; j < n; j++) dfs(dfs, 0, j, pacific);
        
        // Run DFS for Atlantic (bottom & right edges)
        for(int i = 0; i < m; i++) dfs(dfs, i, n-1, atlantic);
        for(int j = 0; j < n; j++) dfs(dfs, m-1, j, atlantic);
        
        // Collect cells that can reach both oceans
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
            }
        }
        
        return res;
    }
};
