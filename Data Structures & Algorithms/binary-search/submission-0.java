class Solution {
    public int search(int[] nums, int target) {
        if(nums.length == 0)
          return -1;

        int high = nums.length -1;
        int low = 0;
        int middle;

       int index = -1;

       while(low <= high)
       {
          middle = low + (high - low)/2;


         if(nums[middle] == target) 
          return middle;

         if(nums[middle] > target)
           high = middle -1 ;
                
         if(nums[middle] < target)
           low = middle  + 1  ;   

       };

           return index;

    };

}
