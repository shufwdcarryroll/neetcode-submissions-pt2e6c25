class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;

        for(int i = 0 ; i < order.size(); i++)
        {
            mp[order[i]] = i;
        };

        for(int i = 0 ; i < words.size() -1 ; i++)
        {
            string w1 = words[i];
            string w2 = words[i+1];

int j = 0;

            for( ; j < min(w1.size(),w2.size()); j++)
            {
                if(mp[w1[j]] < mp[w2[j]])
                {
                    break; // correct order
                }

                if(mp[w2[j]] < mp[w1[j]])
                {
                    return false;
                }

            }

            if(j == min(w1.size(), w2.size()) && w1.size() > w2.size())
                return false;

        }

        return true; 

    }
};