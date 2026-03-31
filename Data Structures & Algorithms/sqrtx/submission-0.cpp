class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        double med = low + ( high - low )/2;

        if( abs(med * med - x) < 1)
          return med;
        while( low <= high )
        {
            if(med*med == x) return med;
            if(med*med < x) low = med +1;
            if(med*med > x) high = med - 1;

            med = low + ( high - low)/2;
        }

        return med  -1 ;
    }
};