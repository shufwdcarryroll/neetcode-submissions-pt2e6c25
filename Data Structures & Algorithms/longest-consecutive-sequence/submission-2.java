class Solution {
    public int longestConsecutive(int[] nums) {
       HashSet<Integer> numSet = new HashSet<>();
       for(int i = 0 ; i < nums.length ; i++) 
       {
        numSet.add(nums[i]);
       };

       int streak = 0;

       for(int i = 0 ; i < nums.length ; i++)
       {

        int currentNum = nums[i];

        int currentStreak = 0;
        while(numSet.contains(currentNum))
        {
            currentStreak++;
            currentNum = currentNum+1;
            streak = Math.max(currentStreak,streak);
        }

       };

       return streak;
    }
}
