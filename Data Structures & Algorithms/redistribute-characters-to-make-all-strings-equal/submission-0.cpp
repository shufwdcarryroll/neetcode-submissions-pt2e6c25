class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        if (n <= 1) return true; // Already "equal" or nothing to move

        // Step 1: Count frequencies of all characters
        // Since there are only 26 lowercase English letters, an array is perfect.
        int counts[26] = {0};

        for (const string& word : words) {
            for (char c : word) {
                counts[c - 'a']++;
            }
        }

        // Step 2: Check if every character count is divisible by n
        for (int i = 0; i < 26; i++) {
            if (counts[i] % n != 0) {
                return false; 
            }
        }

        return true;
    }
};