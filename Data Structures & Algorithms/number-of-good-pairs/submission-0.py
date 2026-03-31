class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        freq = dict();
        count = 0

        for num in nums :
            count = count + freq.get(num,0)
            freq[num] = freq.get(num,0) + 1
        
        return count


