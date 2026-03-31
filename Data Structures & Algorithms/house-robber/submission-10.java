class Solution {
    public int rob(int[] nums) {
       if(nums.length == 1) 
        return nums[0];

        if(nums.length == 2) 
          return Math.max(nums[0],nums[1]);
        
        int prev = Math.max(nums[0],nums[1]);
        int prev2 = nums[0];
        int max = 0;

        for(int i = 2; i < nums.length ; i++)
        {
            int curr = Math.max(prev, prev2 + nums[i]);

          //  max = max + Math.max(prev, prev2 + nums[i]);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
}
