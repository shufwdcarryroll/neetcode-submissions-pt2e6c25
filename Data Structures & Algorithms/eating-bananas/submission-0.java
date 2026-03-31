class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int left = 1;
        int right = 0;
        
        // Find the maximum pile size to set upper bound for binary search
        for (int pile : piles) {
            right = Math.max(right, pile);
        }
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int hours = 0;
            
            // Calculate hours needed with speed = mid
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid;  // Equivalent to ceil(pile/mid)
            }
            
            if (hours > h) {
                // Need to eat faster, increase speed
                left = mid + 1;
            } else {
                // Can finish on time or early, try slower speed
                right = mid;
            }
        }
        
        return left;
    }
}
