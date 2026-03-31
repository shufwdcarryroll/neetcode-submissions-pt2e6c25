class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        dict = {}

        for c in magazine :
            dict[c ] = dict.get(c ,0) + 1
        
        for c in ransomNote : 
            dict[c ] = dict.get(c ,0) - 1
            if(dict[c ] < 0) :
                return False
        
        return True