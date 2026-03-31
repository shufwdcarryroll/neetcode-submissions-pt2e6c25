class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        freq = dict()

        for c in arr :
            freq[c] = freq.get(c,0) + 1
        
        for s in arr :
            if freq[s] == 1 :
                k = k - 1
                if k == 0 :
                    return s
        
        return ""
