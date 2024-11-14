class LRUCache {
private:
    list<pair<int, int>> keyValueList;
    unordered_map<int, list<pair<int, int>>::iterator> pos;
    int capacity;
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
    }
    
    int get(int key) {
        if(pos.count(key)) {
            // Reorder
            keyValueList.splice(keyValueList.begin(), keyValueList, pos[key]);
            return pos[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(pos.count(key)) {
            // Update value of the key from the list
            pos[key]->second = value;
            // Reorder
            keyValueList.splice(keyValueList.begin(), keyValueList, pos[key]);
            return;
        }
        if(keyValueList.size() == capacity) {
            // Remove key
            int keyToBeDeleted = keyValueList.back().first;
            keyValueList.pop_back();
            pos.erase(keyToBeDeleted);
        }
        // Add key
        keyValueList.push_front({key, value});
        pos[key] = keyValueList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
