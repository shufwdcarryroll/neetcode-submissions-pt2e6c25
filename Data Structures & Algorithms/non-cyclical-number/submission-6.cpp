class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;       // ADD THIS

        while(n != 0)
        {
            n = sumOfSquares(getDigits(n));
            if(n == 1) return true;

            if(seen.count(n)) return false;  // REPLACE your "n < 10" check
            seen.insert(n);                  // ADD THIS

            continue;
        }

        return false;
    }
    
    queue<int> getDigits(int n )
    {
        queue<int> dig;
        while(n > 0)
        {
            int rem = n %10;
            dig.push(rem);
            n = n/10;
            
        };

        return dig;
    }

    int sumOfSquares(queue<int> dig)
    {
        int sum = 0;

        while(!dig.empty())
        {
            int d = dig.front();
            sum = sum + d*d;
            dig.pop();
        };

        return sum;
    }
};