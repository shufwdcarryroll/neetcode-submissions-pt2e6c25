class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result = 0;
        
        for (int i = 0; i < 32; i++) {
            result <<= 1;         // Shift result to the left to make room for next bit
            result |= (n & 1);    // Add the last bit of n to result
            n >>= 1;             // Unsigned right shift n (fill with 0s)
        }
        
        return result;  
    }
};
