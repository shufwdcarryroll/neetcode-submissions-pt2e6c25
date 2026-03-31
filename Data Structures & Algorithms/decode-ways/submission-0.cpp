class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        
        int n = s.size();
        vector<int> dp(n + 1, 0);
        
        dp[0] = 1; // empty string
        dp[1] = s[0] != '0' ? 1 : 0; // first char
        
        for (int i = 2; i <= n; i++) {
            // Single digit
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            // Two digits
            int twoDigit = stoi(s.substr(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
    }
};
