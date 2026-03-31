class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int slow = 0;
        for(int fast = 0 ; fast < nums.size(); fast++)
        {
            int i = fast;
            if(nums[i] % 2 == 0)
            {
                swap(nums[i],nums[slow]);
                slow++;
            }
        }

        return nums;
    }
};