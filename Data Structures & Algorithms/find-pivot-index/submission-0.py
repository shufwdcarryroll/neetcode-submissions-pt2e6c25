class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = 0

        for n in nums :
            total = total + n
        
        leftSum = 0

        for i in range(len(nums)) :
            rightSum = total - leftSum - nums[i]

            if ( leftSum == rightSum) :
                return i
            
            leftSum = leftSum + nums[i]
        
        return -1

