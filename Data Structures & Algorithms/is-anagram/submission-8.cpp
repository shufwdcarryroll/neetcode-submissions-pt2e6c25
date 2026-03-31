class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int chart[26] = {0};

        for( char c : s)
        {
            chart[c - 'a']++;
        };

        for( char c : t)
        {
            chart[c - 'a']--;
        };

        for(int i = 0 ; i < 26; i++)
        {
            if(chart[i] > 0) return false;
        }
        return true;
    }
};
