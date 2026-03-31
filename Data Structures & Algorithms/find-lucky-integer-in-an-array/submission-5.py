class Solution:
    def findLucky(self, arr: List[int]) -> int:
        freq = {}
        maxFreq = 0
        no = -1

        for n in arr :
            freq[n] = freq.get(n,0) + 1

        for key in freq :
            if(key == freq[key]) :
                no = max(key,no)
        
        return no

