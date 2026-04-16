class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 0;

        int maxL = 0;
        set<char> inc;

        while(end < s.size())
        {
            if(inc.count(s[end]) == 0)
            {
                inc.insert(s[end]);
                maxL = max(maxL, end - start + 1);
                end++;
            }
            else
            {
              inc.erase(s[start]);
              start++;  
            }
        }

        return maxL;
    }
};
