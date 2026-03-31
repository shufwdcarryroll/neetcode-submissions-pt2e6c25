class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        base = [0] * 26

        for c in chars :
            base[ord(c) - ord('a')] = base[ord(c) - ord('a')]  + 1

        total = 0

        for w in words :
            freq = base.copy()
            valid = True

            for c in w :
                freq[ord(c) - ord('a')] -= 1   # ✅ decrement
                if((freq[ord(c) - ord('a')])  < 0) :
                    valid = False
                    break

            if valid :
                total = total + len(w)
        
        return total
