class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int no = 0;

        for( int n : nums)
        {
            no = no ^ n;
        }

        return no;
    }
};