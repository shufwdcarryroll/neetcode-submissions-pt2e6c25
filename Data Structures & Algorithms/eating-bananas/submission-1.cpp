class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element( piles.begin(), piles.end());

        while( low <= high)
        {
            int mid = low + ( high - low)/2;

            long long th = 0;

            for(int n : piles)
            {
                th += (n + mid - 1)/mid;
            }


            if(th > h )
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low;
    }
};