class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int len1 = word1.size();
        int len2 = word2.size();
        vector<char> sr;
        for(int i = 0 ; i < max(len1,len2); i++)
        {
            if(i < len1)
            {
            sr.push_back(word1[i]);
            }
             if( i < len2)
            {
            sr.push_back(word2[i]);
            }

        };
        string s;
        s.assign(sr.begin(), sr.end());

        return s;
        
    }
};