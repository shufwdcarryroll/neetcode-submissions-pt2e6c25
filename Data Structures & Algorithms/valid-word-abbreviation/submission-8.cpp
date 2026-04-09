class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int slow = 0;
        int slower = 0;
        while (slower < (int)abbr.size())
        {
            if (isalpha(abbr[slower]))  // Fix 1: use isalpha() instead of wrong arithmetic
            {
                if (slow >= (int)word.size() || word[slow] != abbr[slower])
                {
                    return false;
                }
                slow++;
            }
            else
            {
                if (abbr[slower] == '0') return false;  // Fix 3: reject leading zeros

                int num = 0;                             // Fix 2: parse full multi-digit number
                while (slower < (int)abbr.size() && isdigit(abbr[slower]))
                {
                    num = num * 10 + (abbr[slower] - '0');
                    slower++;
                }
                slow += num;
                continue;                               // skip the slower++ at the bottom
            }
            slower++;
        }

        return slow == (int)word.size();                // Fix 4: validate full word consumed
    }
};