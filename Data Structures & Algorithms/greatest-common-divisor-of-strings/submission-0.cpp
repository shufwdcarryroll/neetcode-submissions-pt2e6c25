class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // If they share a common divisor, concatenation must be commutative
        if (str1 + str2 != str2 + str1) return "";
        
        int gcdLen = __gcd((int)str1.size(), (int)str2.size());
        return str1.substr(0, gcdLen);
    }
};