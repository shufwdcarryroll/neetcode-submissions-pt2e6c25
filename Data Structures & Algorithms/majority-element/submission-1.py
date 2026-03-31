class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        mp : dict[int, int] = {}
        size = len(nums)

        for num in nums : 
            mp[num] = mp.get(num,0) + 1
            if mp.get(num,0) > size/2 :
                return num

        return -1 

