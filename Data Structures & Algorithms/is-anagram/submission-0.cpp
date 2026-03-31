class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
         return false;
        
        int count[26] = {0};

        for(int i = 0 ; i < s.length(); i++)
        {
          count[s.at(i) - 'a'] = count[s.at(i) - 'a'] + 1;
          count[t.at(i) - 'a'] = count[t.at(i) - 'a'] - 1;

        };

    
    // Traditional for loop
    for (int i = 0; i < sizeof(count)/sizeof(count[0]); i++) {
            if(count[i] != 0)
                return false;
    }


    

        return true;
    }
};