class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map<int, list<int>::iterator> pos;
    unordered_map<int, pair<int, int>> cache; // key -> (value, freq)
    unordered_map<int, list<int>> freqList;   // freq -> key

    void updateFrequency(int key) {
        int freq = cache[key].second;
        // Remove from current freqList
        freqList[freq].erase(pos[key]);
        if(freqList[freq].empty()) {
            freqList.erase(freq);
            if(freq == minFreq)
                minFreq++;
        }
        // Add to new freqList
        freq++;
        freqList[freq].push_front(key);
        pos[key] = freqList[freq].begin();
        cache[key].second = freq;
    }
public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(cache.count(key)) {
            updateFrequency(key);
            return cache[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            cache[key].first = value;
            updateFrequency(key);
            return;
        }
        if(cache.size() == capacity) {
            int lfuKey = freqList[minFreq].back();
            // Remove LFU item (or LRU if there are multiple LFU items)
            freqList[minFreq].pop_back();
            cache.erase(lfuKey);
            pos.erase(lfuKey);
        }
        // Add new key with freq 1
        freqList[1].push_front(key);
        pos[key] = freqList[1].begin();
        cache[key] = {value, 1};
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
