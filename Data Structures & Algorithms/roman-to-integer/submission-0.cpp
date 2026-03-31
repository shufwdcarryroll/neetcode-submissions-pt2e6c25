class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> sym;
        sym['I'] = 1;
        sym['V'] = 5;
        sym['X'] = 10;
        sym['L'] = 50;
        sym['C'] = 100;
        sym['D'] = 500;
        sym['M'] = 1000;

        int sum = 0 ;

        for( int i = 0 ; i < s.size(); i ++)
        {
            if( i < s.size() -1)
            {
                int firstNp = sym[s[i]];
                int secondNp = sym[s[i+1]];

                if(secondNp > firstNp)
                {
                    sum = sum + secondNp - firstNp;
                    i++;
                }
                else
                {
                   sum = sum +  firstNp;

                }


            }
            else
            {
            sum = sum + sym[s[i]];
            };
        }

        return sum;
    }
};