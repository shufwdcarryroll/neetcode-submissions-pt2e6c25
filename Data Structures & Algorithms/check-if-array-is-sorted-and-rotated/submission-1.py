class Solution:
    def check(self, arr: List[int]) -> bool:
        n = len(arr)
        count = 0
        
        for i in range(n):
            if arr[i] > arr[(i + 1) % n]:
                count += 1
        
        return count <= 1