class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()); // ✅ FIX: min capacity

        int h = 0;
        for(int w : weights)
        {
            h += w;
        };

        while( l <= h)
        {
            int mid = (l+h)/2;
            int daysAns = daysF(weights,mid);
            if(daysAns > days)
            {
                l = mid+1;
            }
            else
            {
                h = mid - 1;
            }

        }

        return l;

    }

    int daysF(vector<int>& weights, int weight)
    {
        int days = 1 ;
        int remWeight = weight;
        int count = 0;

        for(int i = 0 ; i < weights.size(); i++)
        {
            if(remWeight >= weights[i])
            {
                remWeight = remWeight - weights[i];
            }
            else 
            {
               days++;                  // ✅ FIX: new day
                remWeight = weight - weights[i]; // ✅ FIX: load current item

            }
        }

        return days;
    }
};