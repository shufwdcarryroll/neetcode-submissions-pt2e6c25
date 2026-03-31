class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        set_val = set()
        for no in nums :
            if no not in set_val : 
                set_val.add(no)
            else :
                return True
        return False

        