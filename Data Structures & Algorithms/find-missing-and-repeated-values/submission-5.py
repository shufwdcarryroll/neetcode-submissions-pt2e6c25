class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        total = n * n

        freq = {}

        for row in grid :
            for num in row :
                freq[num] = freq.get(num,0) + 1
        
        missing = -1
        repeated = -1

        for i in range(1,total + 1) :
            if i not in freq :
                missing = i
            if freq.get(i,0) == 2 :
                repeated = i
        
        return  [repeated, missing]



