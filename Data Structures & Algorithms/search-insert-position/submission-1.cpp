class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int low = 0;
       int high = nums.size() -1;

       while( low <= high) 
       {

          int med = low + (high - low)/2;

          if(nums[med] == target) return med;
          if(nums[med] < target) low = med + 1;
          if(nums[med] > target) high = med  -1 ;


       }

       return high + 1;
    }
};