class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        
        int count = 0;

        for(int i = 0 ; i < words.size(); i++)
        {
            for(int j = i + 1; j < words.size(); j++)
            {
                count += isPrefixAndSuffixPair(words[i],words[j]);
            }
        }

        return count;
    }

    bool isPrefixAndSuffixPair(string& a , string& b)
    {
        if( (b.substr(0, a.size())) != a )
            return false;

        if( (b.substr(b.size() - a.size() , a.size())) != a )
            return false;

        return true;
    }
};