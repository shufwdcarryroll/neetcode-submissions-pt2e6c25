class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        numnew = nums
        numnew.extend(numnew)
        return numnew
        