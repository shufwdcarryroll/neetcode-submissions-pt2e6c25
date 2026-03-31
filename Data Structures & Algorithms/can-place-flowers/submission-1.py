class Solution:
    def canPlaceFlowers(self, f: List[int], n: int) -> bool:
        count = 0 
        size = len(f)

        for i in range(size) :
            if f[i] == 0 :
                if i == 0 :
                    left = 0
                else :
                    left = f[i-1]
                
                if i == size - 1 :
                    right = 0
                else :
                    right = f[i+1]  

                if left == 0 and right == 0 :
                    f[i] = 1
                    count += 1     

            if count >= n :
                return True      

        return count >= n


