class Solution:
    def isPerfectSquare(self, num: int) -> bool:

        if (num == 1) : 
            return True
            
        half = num//2
        i = 1

        while( i <=  half) :
            if ( i * i == num ) :
                return True
            i = i + 1
        
        return False
        