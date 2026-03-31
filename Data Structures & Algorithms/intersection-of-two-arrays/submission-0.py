class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s1 = set()
        s2 = set()
        smaller = set()

        for n in nums1 :
            s1.add(n)
        for n in nums2 :
            s2.add(n)
        
        result = []
        if (len(s1) <= len(s2)) :
            smaller = s1
        else :
            smaller = s2


        for s in smaller :
            if s in s1 and s in s2 :
                result.append(s)
        
        return result