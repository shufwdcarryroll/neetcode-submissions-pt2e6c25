class Solution:
    def countSeniors(self, details: List[str]) -> int:
        count = 0

        for c in details :
            age = int(c[11]) * 10 + int( c[12])

            if age > 60 :
                count = count + 1
        
        return count
        