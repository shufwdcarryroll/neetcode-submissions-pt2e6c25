class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        for(int i = 1 ; i < nums.size(); i = i+2)
        {
            if(nums[i] < nums[i-1])
            {
                swap(nums[i],nums[i-1]);
            }
        };

        for(int i = 0 ; i < nums.size(); i = i+2)
        {
            if(i > 1 && (nums[i] > nums[i-1]))
            {
                swap(nums[i],nums[i-1]);
            }
        };
    }
};


