class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size() > s2.size()) return false;
        unordered_map<int,int> s1C;
        unordered_map<int,int> s2C;

        for(int i = 0 ; i < s1.size(); i++)
        {
            s1C[s1[i] - 'a']++;
            s2C[s2[i] - 'a']++;

        };

        if (matches(s1C, s2C)) return true;

        for(int i = s1.size(); i < s2.size(); i++)
        {
            s2C[s2[i] - 'a']++;
            s2C[s2[i - s1.size()] - 'a']--;
            if(matches(s1C,s2C))
            {
                return true;
            }


        }

        return false;

    }

    bool matches(unordered_map<int,int> t1, unordered_map<int,int> t2)
    {
        for(int i = 0; i < t1.size(); i++)
        {
            if(t1[i] != t2[i]) return false;
        }

        return true;
    }

};

