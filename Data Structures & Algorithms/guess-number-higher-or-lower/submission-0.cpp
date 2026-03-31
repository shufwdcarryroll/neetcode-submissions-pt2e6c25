/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;

        int no;

        while( low <= high)
        {
            int med = low + (high - low)/2;

            if(0 == guess(med)) 
            {
                return med;
            }
            else if(guess(med) > 0) 
            {
                low = med + 1;
            }
            else
            {
                high = med -1;
            }


        }

        return 1;
    }
};