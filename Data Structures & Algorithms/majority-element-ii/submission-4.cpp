class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;  // no , freq
        unordered_set<int> nBy3Freq;

        for (int num : nums)
        {
            map[num]++;   // simpler: handles both insert + increment

            if (map[num] > nums.size()/3) {
                nBy3Freq.insert(num);
            }
        }

        return vector<int>(nBy3Freq.begin(), nBy3Freq.end());
    }
};
