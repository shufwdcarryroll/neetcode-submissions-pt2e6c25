class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int len = ((nums.size() -k) + 1);

        for(int i = 0 ; i <  len; i++)
        {
            vector<int> sub(nums.begin() + i, nums.begin() + i + k );
            ans.push_back(maxN(sub));
        }

        return ans;
    }

    int maxN(vector<int> &nums)
    {
        int maxN = INT_MIN;
        for(int n : nums)
        {
            maxN = max(n,maxN);
        };
        return maxN;
    }
};