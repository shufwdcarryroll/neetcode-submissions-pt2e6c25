class Solution {
public:
    int minOperations(string s) {
        int sW0 = 0;
        int sW1 = 0;

        for(int i = 0 ; i < s.size(); i++)
        {
            char expected0 = (i % 2 == 0) ? '0' : '1';
            char expected1 = (i % 2 == 0) ? '1' : '0';

            if (s[i] != expected0) sW0++;
            if (s[i] != expected1) sW1++;
        }

        return min(sW0, sW1);
    }
};