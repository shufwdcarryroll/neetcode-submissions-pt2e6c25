class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    map<int, set<int>, greater<int>> freqToNums;

    for (auto &p : freq) {
        freqToNums[p.second].insert(p.first);
    }

    vector<int> result;
    int count = 0;

    for (auto &p : freqToNums) {
        for (int num : p.second) {
            if (count < k) {
                result.push_back(num);
                count++;
            } else {
                break;
            }
        }
        if (count >= k) break;
    }

    return result;

    }
};
