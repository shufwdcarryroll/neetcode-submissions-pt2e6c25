class Solution {
public:
    string minWindow(string s, string t) {
  
       unordered_map<char, int> need , window;
       for(char c : t) need[c]++;
       int have = 0, needSize = need.size();
       int left = 0, minLen = INT_MAX, start = 0;

       for(int i = 0 ; i < s.size(); i++)
       {
        int right = i;
        char c = s[right];
        window[c]++;
        if(need.count(c) && window[c] == need[c]) have++;

        while(have == needSize)
        {
            if(right - left +1 < minLen)
            {
                minLen = right - left +1;
                start = left;

            }

            char d = s[left++];
            if(need.count(d) && window[d]-- == need[d]) have--;

        }
       }

       return minLen == INT_MAX ? "" : s.substr(start,minLen);
    }

};
