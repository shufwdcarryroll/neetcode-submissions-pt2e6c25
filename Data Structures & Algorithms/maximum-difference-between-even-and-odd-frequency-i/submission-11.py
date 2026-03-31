class Solution:
    def maxDifference(self, s: str) -> int:
        freq = dict()

        for c in s :
            freq[c] = freq.get(c,0) + 1
        
        maxOdd = float('-inf')
        minEven = float('inf')

        for key, value in freq.items() :
            f = value

            if f % 2 == 1 :
                maxOdd = max(maxOdd,  f)
            else :
                minEven = min(minEven,f)

        return maxOdd - minEven
