class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> newVect(2*nums.size());

        for(int i = 0 ; i < nums.size() ; i++)
        {
            newVect[i] = nums[i];
            newVect[i + nums.size()] =  nums[i];
        }

        return newVect;

    }
};