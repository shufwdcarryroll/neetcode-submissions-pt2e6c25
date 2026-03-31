class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int no = nums.size();

        for(int i = 0 ; i < nums.size(); i ++)
        {
            no ^= i;
        }

        for(int num : nums)
        {
            no ^= num;
        };

        return no;
    }
};
