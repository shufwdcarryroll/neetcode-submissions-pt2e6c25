class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string sub = s.substr(i, j - i + 1);
                if (isPalindrome(sub) && sub.size() > maxLen) {
                    ans = sub;
                    maxLen = sub.size();
                }
            }
        }
        return ans;
    }

private:
    bool isPalindrome(const string &str) {
        int l = 0, r = str.size() - 1;
        while (l < r) {
            if (str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
