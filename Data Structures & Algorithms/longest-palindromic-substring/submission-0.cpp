class Solution {
public:
    // Function to find the longest palindromic substring
    string longestPalindrome(string s) {
        int n = s.size();          // Length of the input string
        int start = 0, maxLen = 0; // start index and max length of the palindrome found

        // Lambda function to expand around a center
        auto expand = [&](int left, int right) {
            // Expand while characters on both sides are equal and within bounds
            while(left >= 0 && right < n && s[left] == s[right]) {
                left--;  // Move left pointer outward
                right++; // Move right pointer outward
            }
            // Update max palindrome if this one is longer
            if(right - left - 1 > maxLen) {
                start = left + 1;      // Update starting index
                maxLen = right - left - 1; // Update max length
            }
        };

        // Loop through each character as a potential center
        for(int i = 0; i < n; i++) {
            expand(i, i);     // Odd length palindrome (single center)
            expand(i, i + 1); // Even length palindrome (double center)
        }

        // Return the longest palindromic substring found
        return s.substr(start, maxLen);
    }
};

/*
Algorithm Idea:
- A palindrome reads the same forwards and backwards.
- For each character in the string, try to expand outwards to find the largest palindrome centered at that character (odd length) or between two characters (even length).
- Keep track of the longest palindrome seen so far.

Time Complexity: O(n^2)
Space Complexity: O(1)

Example Test Cases:
1. Input: "babad"
   Output: "bab" or "aba"  // Both are valid
2. Input: "cbbd"
   Output: "bb"
3. Input: "a"
   Output: "a"
4. Input: "ac"
   Output: "a" or "c"
*/
