class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       if(nums.size() == 0 ) return 0;

       unordered_set<int> noSet(nums.begin(), nums.end());
       int longest = 1;

       for(int num  : nums)
       {
        int curNum = num;
        int currStreak = 0;
        if(!noSet.count(num - 1)) {

        while(noSet.count(curNum))
        {
            curNum++;
            currStreak++;
        };
            }

        longest = max(longest,currStreak);
       };

       return longest;
    }
};