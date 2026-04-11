class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> mp;
        for(int n : nums)
        {
            mp[n]++;
        }

        vector<int> res;

        for (auto &p : mp) {
            for(int i = 0 ; i < p.second; i++)
            {
                res.push_back(p.first);
            }
        }

        nums = res;
    }
};