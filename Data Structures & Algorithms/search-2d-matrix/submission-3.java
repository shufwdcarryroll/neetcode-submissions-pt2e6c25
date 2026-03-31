class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
       int rows = matrix.length;
       int cols = matrix[0].length;

       int rowStart = 0;
       int rowEnd = rows -1;
       
       boolean found = false;

       while(rowStart <= rowEnd)
       {
          int midRow = rowStart + (rowEnd - rowStart)/2;

          int no = matrix[midRow][0];

          if(no < target)
          {
                rowStart = midRow + 1;

          }
          if(no == target)
          {
            found = true;
            break;
          }

          if(no > target)
          {
            rowEnd = midRow -1;
          }

          if( binarySearch(matrix[midRow], target) > 0)
        {
            found = true;
            break;
        }
       }


       return found;
    
    }

    public static int binarySearch(int[] nums, int target)
    {
        int low = 0; 
        int high = nums.length -1;

        while( low <= high)
        {
            int mid = low + (high - low)/2;

            if(nums[mid] == target) 
              return mid;
            if(nums[mid] < target )
               low = mid +1;
            if(nums[mid] > target )
               high = mid - 1;
        };

        return -1;
    }
}
