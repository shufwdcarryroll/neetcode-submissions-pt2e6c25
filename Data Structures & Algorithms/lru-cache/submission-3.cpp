class LRUCache {
    int capacity;
    list<pair<int,int>> lru;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        auto it = mp[key];
        int val = it->second;
        lru.erase(it);
        lru.push_front({key,val});
        mp[key] = lru.begin();
        return val;
    }
    
    void put(int key, int value) {
                if (mp.find(key) != mp.end()) {
            // erase old position
            lru.erase(mp[key]);
        } else if ((int)lru.size() == capacity) {
            // evict least recently used (back)
            auto last = lru.back();
            mp.erase(last.first);
            lru.pop_back();
        }
        
        // insert new at front
        lru.push_front({key, value});
        mp[key] = lru.begin();
    }    
    
};
