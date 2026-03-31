class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        long long med;   // fix overflow risk

        while (low <= high) {
            med = low + (high - low) / 2;
            long long sq = med * med;  // compute once

            if (sq == x) return med;
            if (sq < x) low = med + 1;
            else high = med - 1;
        }

        return high;  // instead of med - 1 hack
    }
};
