class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;

        for(int i = digits.size() - 1; i >= 0 ; i--)
        {
            if(digits[i] < 9)
            {

               digits[i] = digits[i]  + carry ; 
               carry = 0;             
            }
            else
            {
                if(0 == i && carry > 0)
                    digits[i] = 9 + carry;
                else
                {
                  if( carry > 0 )
                  {
                    digits[i] = 0;
                  }
                  else
                  {
                    digits[i] = digits[i];
                  }
                }
                
            }
        }
        vector<int> nums = digits;
        vector<int> digitsNew;
        for (int n : nums) {
            if (n == 0) { digitsNew.push_back(0); continue; }
            string s = to_string(n);
            for (char c : s) digitsNew.push_back(c - '0');
        }

        return digitsNew;
    }
};
