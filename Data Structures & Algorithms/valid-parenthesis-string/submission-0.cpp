class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;
        for (char c : s) {
            if (c == '(') {
                lo++;
                hi++;
            } else if (c == ')') {
                lo = max(lo - 1, 0);
                hi--;
            } else { // c == '*'
                lo = max(lo - 1, 0);
                hi++;
            }
            
            if (hi < 0) return false;
        }
        return lo == 0;
    }
};
