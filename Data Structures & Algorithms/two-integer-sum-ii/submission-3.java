class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int low = 0;
        int high = numbers.length - 1;

        while(low < high)
        {
            int sum = numbers[high] + numbers[low];
            if(sum == target)
              return new int[] {low+1,high+1};
            if(sum > target)
              high--;
            if(sum < target)
              low++;

        };

        return new int[] {-1,-1};


    }
}
