class Solution {
public:
    string maximumOddBinaryNumber(string s) {
                int ones = 0;
        
        for (char c : s) {
            if (c == '1') ones++;
        }

        int zeros = s.size() - ones;

        // construct result
        string result = string(ones - 1, '1') + 
                        string(zeros, '0') + 
                        "1";

        return result;
    }
};