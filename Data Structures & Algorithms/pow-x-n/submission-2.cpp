class Solution {
public:
    double myPow(double x, int n) {

       //return pow(x,n);
       // FIX: handle negative n safely with long long
       double loop = x;
       long long pow = n;
       if (pow < 0) {
           loop = 1 / loop;
           pow = -pow;
       }

       double ans = 1; 

       // KEEP special cases for ±1 (optional)
       if (x == 1) return 1;
       if (x == -1) return (pow % 2 == 0) ? 1 : -1;

       // Fast exponentiation loop
       while (pow > 0) {
           if (pow % 2 == 1) {   // if odd
               ans *= loop;
           }
           loop *= loop;         // square the base
           pow /= 2;             // halve the exponent
       }

       return ans;
    }
};
