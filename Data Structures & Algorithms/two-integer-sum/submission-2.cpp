class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      //

      std::unordered_map<int, int> hashMap;
      for(int i = 0 ; i < nums.size(); i++)
      {
        hashMap[nums[i]] = i;
      };

       for(int i = 0 ; i < nums.size(); i++)
      {
        int compliment = target - nums[i];
        if(hashMap.find(compliment) != hashMap.end())
        {
            if(i != hashMap[compliment])
             return { i, hashMap[compliment]}; 
        }
      };

      return {0,0};


    }
};
