class MedianFinder {
public:
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, greater<int>> minHeap; // min heap


    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);

        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if(maxHeap.size() < minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
    }
    
    double findMedian() {
                if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top(); // odd count
        }
    }
};
