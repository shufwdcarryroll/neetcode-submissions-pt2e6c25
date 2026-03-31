class TimeMap {
public:

    // key -> vector of (timestamp, value)
    unordered_map<string,vector<pair<int,string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
       if(store.find(key) == store.end()) return "";

       auto &arr = store[key];
       int low = 0;
       int high = arr.size() - 1;
       string ans = "";

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid].first <= timestamp) {
                ans = arr[mid].second; // possible candidate
                low = mid + 1; // search later timestamps
            } else {
                high = mid - 1; // too late, search earlier
            }
        }

        return ans;
    }
};
