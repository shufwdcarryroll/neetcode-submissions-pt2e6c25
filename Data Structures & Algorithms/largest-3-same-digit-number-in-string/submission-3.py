class Solution:
    def largestGoodInteger(self, num: str) -> str:
        result = ""

        for i in range(0, len(num) - 2) :
            if( num[i] == num[i+1] and num[i] == num[i+2]) :
                curr = num[i:i+3]
                result = max(result, curr)
        
        return result

