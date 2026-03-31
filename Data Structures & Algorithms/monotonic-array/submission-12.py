class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        if not nums:
            return True  # or handle according to your edge-case rules

        increasing = True  # non-decreasing
        decreasing = True  # non-increasing

        for i in range(1, len(nums)):
            if nums[i] < nums[i - 1]:
                increasing = False
            if nums[i] > nums[i - 1]:
                decreasing = False

            # Early exit: neither trend is possible
            if not increasing and not decreasing:
                return False

        return True