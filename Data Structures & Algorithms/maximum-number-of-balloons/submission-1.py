class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        from collections import Counter

        freq = Counter(text)

        # Each balloon uses: b(1), a(1), l(2), o(2), n(1)
        return min(
            freq.get('b', 0),
            freq.get('a', 0),
            freq.get('l', 0) // 2,
            freq.get('o', 0) // 2,
            freq.get('n', 0)
        ) 