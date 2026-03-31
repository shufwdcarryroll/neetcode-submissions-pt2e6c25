class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fcount = 0;
        int tcount = 0;
        int twcount = 0;

        for(int bill : bills)
        {
            if(bill == 5) 
            {
                fcount++;
                continue;
            }
            if(bill == 10)
            {
              tcount++;
              if(fcount > 0)
              {
                 fcount--;
              }
              else
              {
                 return false;
              }
            }

            if(bill == 20)
            {
              twcount++;
              if(fcount >= 1 && tcount >= 1)
              {
                 fcount--;
                 tcount--;
              }
              else if(fcount >= 3)
              {
                 fcount = fcount - 3;
              }
              else
              {
                 return false;
              }
            }
               

                
            }

            return true;
        }
};
