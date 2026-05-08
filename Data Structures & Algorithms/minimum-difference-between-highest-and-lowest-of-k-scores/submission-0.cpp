class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int minDif = INT_MAX;
        if(nums.size() == 1) return 0;
        sort(nums.begin(), nums.end());

        for(int i = 0; i <= (nums.size() - k); i++)
        {
            int minN = nums[i];
            int maxN = nums[i+k-1];
            minDif = min(minDif,abs(minN - maxN));
        }

        return minDif;
    }

    int minNum(vector<int>& nums, int start, int end)
    {
        int minN = nums[0];
        for(int i = start ; i < end ; i++)
        {
            minN = min(minN,nums[i]);
        }

        return minN;
    }

    int maxNum(vector<int>& nums, int start, int end)
    {
        int maxN = nums[0];
        for(int i = start ; i < end ; i++)
        {
            maxN = min(maxN,nums[i]);
        }

        return maxN;
    }
};