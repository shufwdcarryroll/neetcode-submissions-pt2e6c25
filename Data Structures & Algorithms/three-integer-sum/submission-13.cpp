class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

               
        vector<vector<int>> ans ;

        set<int> hasNo; 

        for(int i = 0 ; i < nums.size(); i++)
        {
            vector<int> newVec = nums;
            newVec.erase(newVec.begin() + i);
           // newVec.erase(nums[i]);
            vector<vector<int>> a2 = twoSum(newVec, - nums[i]);
            if(size(a2))
            {
                for( vector<int> a : a2)
                {
                ans.push_back({nums[i],a[0],a[1]});
                };
            }
        }


                    for (auto &v : ans) {
                sort(v.begin(), v.end());
            }

            sort(ans.begin(), ans.end());

            ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;

    }

    vector<vector<int>> twoSum(vector<int>& nums, int target)
    {
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans ;

        set<int> hasNo;

        for(int i = 0 ; i < nums.size(); i++)
        {
            if(hasNo.count(target - nums[i]))
            {
                ans.push_back({nums[i],target - nums[i]});
            }
            else
            {
                hasNo.insert(nums[i]);
            }
        }

        return ans;
    }
};