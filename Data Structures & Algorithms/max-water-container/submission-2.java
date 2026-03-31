class Solution {
    public int maxArea(int[] heights) {
      int Area = 0;
      int low = 0;
      int high = heights.length - 1;

      while(low <= high)
      {
          Area = Math.max(Area, (high - low) * Math.min(heights[low],heights[high]));
          if(heights[low] >= heights[high])
          {
                high--;
          }
          else
          {
              low++;
          };
      };

      return Area; 
    }
}
