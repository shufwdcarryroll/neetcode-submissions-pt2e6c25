class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Count frequency of each number
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Use a min-heap to keep top k frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto& entry : freq) {
            minHeap.push({entry.second, entry.first});  // {frequency, number}
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Extract the top k elements from the heap
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
