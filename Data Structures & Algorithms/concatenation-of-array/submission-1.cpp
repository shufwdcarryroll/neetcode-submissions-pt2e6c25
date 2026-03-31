class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> nums2(2 * nums.size());

        for(int i = 0 ; i < nums.size(); i++)
        {
            nums2[i] = nums[i];
            nums2[i + nums.size()] = nums[i];
        }

        return nums2;
    }
};