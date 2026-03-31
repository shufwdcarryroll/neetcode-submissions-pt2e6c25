class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> no;

        for(int i = 0 ; i < nums.size(); i++)
        {
            no[nums[i]] = i;
        };

        for(int i = 0 ; i < nums.size(); i++)
        {
           if (no.find(target - nums[i]) != no.end() && no[target - nums[i]] != i)  
              return { i , no[target - nums[i]] };
        };

        return {-1,-1};
    }
};