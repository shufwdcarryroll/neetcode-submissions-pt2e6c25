class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        //try to decompose to a 2sum problem
        // int target = 0
        // loop thru all element, 
        Arrays.sort(nums);  // Sort the array first

        Set<List<Integer>> list = new HashSet<>();

        for(int i = 0 ; i < nums.length ; i++)
        {
            HashSet<Integer> seen = new HashSet<>();

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            //seen.add(nums[i]);
            int target = -1 * nums[i];
            for(int j = i+1 ; j < nums.length ;j++)
            {
                int secondNo = nums[j];
                int thirdNo = target - secondNo;

           
                if(seen.contains(thirdNo))
                 {
                    List<Integer> allElement = new ArrayList<>();
                    allElement.add(nums[i]);
                    allElement.add(secondNo);
                    allElement.add(thirdNo);
                    Collections.sort(allElement); 
                    list.add(allElement);


                 }

                 seen.add(secondNo);
            }
        }

          return new ArrayList<>(list);

    }
}
