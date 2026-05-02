class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector<int> res(nums.size(),0);
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(i == 0)
            {
                res[i] = nums[i];
            }
            else if(i == 1)
            {
                res[i] = max(nums[0],nums[1]);
            }
            else
            {
                res[i] = max(nums[i] + res[i-2], res[i-1]);
            }
        }
        return res[nums.size() - 1];
    }

    int robRec(vector<int>& nums,int i)
    {
        if(i == 0) return nums[0];
        if(i == 1) return max(nums[0],nums[1]);

        return max(nums[i] + robRec(nums,i-2), robRec(nums, i-1));
    }
};