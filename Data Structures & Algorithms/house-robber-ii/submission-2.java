class Solution {
    public int rob(int[] nums) {

        int n = nums.length;
        if (n == 1) return nums[0]; // only one house
        if (n == 2) return Math.max(nums[0], nums[1]); // two houses

       return Math.max(robOrignal(Arrays.copyOfRange(nums, 1, n)),
       robOrignal(Arrays.copyOfRange(nums, 0, n-1))); 
    }

    public int robOrignal(int[] nums) {
       if(nums.length == 1)
        return nums[0];

       if(nums.length == 2)
        return Math.max(nums[0],nums[1]);

        int prev2 = nums[0];
        int prev1 = Math.max(nums[1],nums[0]);
       
        for(int i = 2; i < nums.length ; i++)
        {
            int curr = Math.max(prev1, prev2 + nums[i]);
             int temp = prev1;

            prev1 = curr;
            prev2 = temp;
        }
        return(prev1);
    }
}