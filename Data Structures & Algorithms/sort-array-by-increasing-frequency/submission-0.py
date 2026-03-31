class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        freq = Counter(nums)
        
        # Sort by (frequency asc, value desc)
        nums.sort(key=lambda x: (freq[x], -x))
        
        return nums      