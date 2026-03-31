class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        count = 0
        s1 = len(haystack)
        s2 = len(needle)

        for i in range(s1) :
            if i + s2 <= s1 :
                if haystack[i:i+s2] == needle :
                    return i
        
        return -1