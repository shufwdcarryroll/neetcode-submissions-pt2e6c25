class Solution {
public:
    int countOdds(int low, int high) {
        bool islowOdd = low % 2 == 1;
        bool ishighOdd = high % 2 == 1;

        if(islowOdd + ishighOdd == 0 )
        {
            return (high - low)/2;

        }
        else 
        {
            return (high - low)/2 + 1;

        }

    }
};