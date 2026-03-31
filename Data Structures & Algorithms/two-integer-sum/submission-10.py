class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict_ele = {}
        for i,val in enumerate(nums):
            dict_ele[val] = i
        
        for i,num in enumerate(nums):
            if dict_ele.get( target - num, -1) != -1 and dict_ele[target - num] != i:
                return [ i, dict_ele[ target - num] ]

        return [-1,-1]