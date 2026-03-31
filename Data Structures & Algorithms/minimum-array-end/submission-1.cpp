class Solution {
public:
    long long minEnd(int n, int x) {
        // We need to find the (n-1)th number after x that maintains
        // the property that AND of all numbers equals x
        
        long long result = x;  // Start with x as base
        long long increment = n - 1;  // We need n-1 more numbers after x
        
        // Find positions where x has 0 bits (free positions)
        // We'll use these positions to encode our increment
        long long bitPos = 0;
        
        while (increment > 0) {
            // Find next position where x has a 0 bit
            while (bitPos < 64 && ((long long)x >> bitPos) & 1) {
                bitPos++;
            }
            
            // If the current bit of increment is 1, set this free position
            if (increment & 1) {
                result |= (1LL << bitPos);
            }
            
            increment >>= 1;  // Move to next bit of increment
            bitPos++;         // Move to next bit position
        }
        
        return result;
    }
};

/*
Alternative approach using bit manipulation:

class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;
        long long mask = 1;
        n--; // We need n-1 increments from the base value x
        
        while (n > 0) {
            // Find the next bit position where x has 0
            while ((mask & x) != 0) {
                mask <<= 1;
            }
            
            // If the lowest bit of n is 1, set this position in result
            if (n & 1) {
                result |= mask;
            }
            
            mask <<= 1;
            n >>= 1;
        }
        
        return result;
    }
};

Time Complexity: O(log n + log x) - we iterate through bits
Space Complexity: O(1)

Example walkthrough for n=3, x=4:
- x = 4 (binary: 100)
- We need 2 more numbers after 4
- Free positions: bits 0 and 1
- increment = 2 (binary: 10)
- Set bit 1 in result: 100 | 010 = 110 = 6

Example walkthrough for n=2, x=7:
- x = 7 (binary: 111) 
- We need 1 more number after 7
- Free positions: bit 3 and higher
- increment = 1 (binary: 1)
- Set bit 3 in result: 0111 | 1000 = 1111 = 15
*/