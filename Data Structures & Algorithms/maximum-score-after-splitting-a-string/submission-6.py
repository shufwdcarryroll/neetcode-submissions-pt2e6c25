class Solution:
    def maxScore(self, s: str) -> int:
        totalOnes = 0
        s = s.strip('"')

        for c in s :
            if c == '1' :
                totalOnes += 1
        
        maxScore = 0
        leftZeros = 0
        rightOnes = totalOnes

        for i in range(len(s) -1) :
            if s[i] == '0':
                leftZeros += 1
            else :
                rightOnes -= 1
            
            maxScore = max(maxScore, leftZeros + rightOnes)

        return maxScore
