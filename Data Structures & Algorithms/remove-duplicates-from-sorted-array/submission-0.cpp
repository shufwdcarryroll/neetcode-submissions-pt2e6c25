class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> no;
        for(int n : nums)
        {
            no.insert(n);
        };
        nums.clear();
        nums.insert(nums.end(),no.begin(),no.end());
        sort(nums.begin(), nums.end());
        return  nums.size() ;
    }
};