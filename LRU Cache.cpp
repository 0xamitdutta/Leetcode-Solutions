class LRUCache {
private:
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int capacity;
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
    }
    
    int get(int key) {
        if(m.count(key)) {
            auto itr = m[key];
            l.splice(l.begin(), l, m[key]);
            return m[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key)) {
            // Update value of the key from the list
            m[key]->second = value;
            // Reorder
            l.splice(l.begin(), l, m[key]);
            return;
        }
        if(l.size() == capacity) {
            // Remove key
            int keyToBeDeleted = l.back().first;
            l.pop_back();
            m.erase(keyToBeDeleted);
        }
        // Add key
        l.push_front({key, value});
        m[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
