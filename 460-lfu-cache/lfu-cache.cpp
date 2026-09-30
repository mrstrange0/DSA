class LFUCache {
public:

    struct Node {
        int key, value, freq;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> mp;                 // key -> node
    unordered_map<int, list<Node*>> freqList;     // freq -> nodes

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void removeNode(Node* node) {
        int f = node->freq;

        freqList[f].remove(node);

        if (freqList[f].empty()) {
            freqList.erase(f);

            if (minFreq == f)
                minFreq++;
        }
    }

    void addNode(Node* node) {
        freqList[node->freq].push_front(node);
    }

    void increaseFreq(Node* node) {
        int oldFreq = node->freq;

        freqList[oldFreq].remove(node);

        if (freqList[oldFreq].empty()) {
            freqList.erase(oldFreq);

            if (minFreq == oldFreq)
                minFreq++;
        }

        node->freq++;

        freqList[node->freq].push_front(node);
    }

    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        increaseFreq(node);

        return node->value;
    }

    void put(int key, int value) {

        if (capacity == 0)
            return;

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            increaseFreq(node);

            return;
        }

        // Cache is full
        if (mp.size() == capacity) {

            // Least frequently used
            int f = minFreq;

            // Among same frequency,
            // remove the least recently used
            Node* victim = freqList[f].back();

            mp.erase(victim->key);
            freqList[f].pop_back();

            delete victim;
        }

        // Insert new node
        Node* node = new Node(key, value);

        mp[key] = node;

        minFreq = 1;

        freqList[1].push_front(node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */