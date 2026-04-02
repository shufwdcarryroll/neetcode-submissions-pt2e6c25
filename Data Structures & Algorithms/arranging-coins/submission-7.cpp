class Solution {
public:
    int arrangeCoins(int n) {

        if(n == 1) return 1;
        for(long long i = 1 ; i <= n ; i++)
        {
            if( (i)*(i+1)/2 >= n)
                return i-1;
        }

        return -1;
    }
};