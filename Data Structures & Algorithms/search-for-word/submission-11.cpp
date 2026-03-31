class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
       int rows = board.size();
       int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int index) {
        // Base case: all characters matched
        if (index == word.size()) {
            return true;
        }


        if (row < 0 || col < 0 || 
            row >= board.size() || col >= board[0].size() || 
            board[row][col] != word[index]) {
            return false;
        }

        // Temporarily mark the cell as visited
        char temp = board[row][col];
        board[row][col] = '#';  // any non-alphabetic char will work

        // Explore all four directions
        bool found = dfs(board, word, row + 1, col, index + 1) ||
                        dfs(board, word, row - 1, col, index + 1) ||
                        dfs(board, word, row, col + 1, index + 1) ||
                        dfs(board, word, row, col - 1, index + 1);

        // Backtrack
        board[row][col] = temp;

        return found;
    }
};
