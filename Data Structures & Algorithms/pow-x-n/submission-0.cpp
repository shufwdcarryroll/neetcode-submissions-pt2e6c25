class Solution {
public:
    double myPow(double x, int n) {
     long N = n;

     if(n < 0) 
     {
         x = 1/x;
         N = -N;
     };  

     double result = 1.0;

     while(N >0)
     {
        result = result * x;
        N--;
     }

     return result;
    }
};
