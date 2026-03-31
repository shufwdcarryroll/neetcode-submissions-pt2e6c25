class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        numnew = nums.copy()
        numnew.extend(numnew)
        return numnew
        