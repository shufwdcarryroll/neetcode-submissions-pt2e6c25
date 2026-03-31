class Solution {
public:
    int maxDepth(string s) {
        int maxD = 0;
        int curr = 0;
        for(int i = 0 ; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                curr++;
                maxD = max(maxD,curr);
            }

            if(s[i] == ')')
            {
                curr--;
            }
        }

        return maxD;
    }
};