class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxOne = 0
        cur = 0

        for num in nums : 
            if num == 1 :
                cur = cur + 1
            else :
                cur = 0
            maxOne = max(cur,maxOne)
        
        return maxOne
        