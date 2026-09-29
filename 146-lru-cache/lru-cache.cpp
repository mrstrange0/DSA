class LRUCache {
public:
    int capacity;

    // {key, value}
    list<pair<int, int>> dll;

    // key -> iterator pointing to node in dll
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        // Key doesn't exist
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // Get iterator
        auto it = mp[key];

        // Store value
        int value = it->second;

        // Move this node to front (most recently used)
        dll.erase(it);
        dll.push_front({key, value});

        // Update iterator
        mp[key] = dll.begin();

        return value;
    }
    
    void put(int key, int value) {
        // Key already exists
        if (mp.find(key) != mp.end()) {
            // Remove old node
            dll.erase(mp[key]);
        }

        // Insert at front
        dll.push_front({key, value});
        mp[key] = dll.begin();

        // Capacity exceeded
        if (dll.size() > capacity) {
            // Last node = least recently used
            auto last = dll.back();

            // Remove from map
            mp.erase(last.first);

            // Remove from list
            dll.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */