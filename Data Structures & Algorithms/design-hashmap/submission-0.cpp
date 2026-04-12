class MyHashMap {
private:
    static const int SIZE = 10000;          // Size of the hash table
    vector<pair<int,int>> table[SIZE];      // Array of vectors for chaining

    int hash(int key) {
        return key % SIZE;                   // Simple modulo hash
    }

public:
    MyHashMap() {
        // Nothing needed here
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        for (auto &p : table[idx]) {
            if (p.first == key) {
                p.second = value;            // Update existing key
                return;
            }
        }
        table[idx].push_back({key, value}); // Insert new key
    }
    
    int get(int key) {
        int idx = hash(key);
        for (auto &p : table[idx]) {
            if (p.first == key) return p.second;
        }
        return -1;                            // Key not found
    }
    
    void remove(int key) {
        int idx = hash(key);
        auto &chain = table[idx];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->first == key) {
                chain.erase(it);             // Remove key
                return;
            }
        }
    }
};


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */