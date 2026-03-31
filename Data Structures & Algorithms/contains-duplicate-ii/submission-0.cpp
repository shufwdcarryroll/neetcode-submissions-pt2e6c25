class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        unordered_set<int> mps;
        for(int i = 0 ; i < nums.size() ; i ++)
        {
            if(mps.find(nums[i]) == mps.end())
            {
                mps.insert(nums[i]);
                mp[nums[i]] =i;
            }
            else
            {
                int posPrev = mp[nums[i]];
                if(abs(posPrev - i) <= k)
                {
                    return true;
                }
                else
                {
                    mp[nums[i]] =i;

                }

            }

        }

        return false;
    }
};