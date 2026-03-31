class CountSquares {
public:
    unordered_map<int, unordered_map<int,int>> points;

    CountSquares() {}

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        points[x][y]++;
    }

    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int total = 0;

        if (!points.count(x)) return 0;

        for (auto& [col, freq] : points) { // col = x2
            int x2 = col;
            if (x2 == x) continue; // horizontal side must be non-zero

            int d = x2 - x; // side length
            // Check upper square
            total += freq[y] * points[x][y + d] * points[x2][y + d];
            // Check lower square
            total += freq[y] * points[x][y - d] * points[x2][y - d];
        }

        return total;
    }
};
