class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int low = 0 ;
        int high = row*col - 1;

        while ( low <= high)
        {
            int med = low + (high - low)/2;

            int r = med/col;
            int c = med % col;

            if(matrix[r][c] == target) return true;
            if(matrix[r][c] < target) low = med + 1;
            if(matrix[r][c] > target) high = med - 1;


        }

        return false;
    }
};