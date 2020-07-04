class LRUCache {
    int size;
    list<pair<int, int>> li; // For removal in O(1) by cache eviction policy
    unordered_map<int, list<pair<int, int>>::iterator> m; // For searching in O(1)
public:
    // Inilializer list
    LRUCache(int capacity) : size(capacity){
    }
    
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;
        
        li.splice(li.begin(), li, m[key]); 
        return m[key]->second;
    }
    
    void put(int key, int value) {
        if(get(key) != -1){
            m[key]->second = value;
            return;
        }
        
        if(m.size() == size){
            int k = li.back().first;
            li.pop_back();
            m.erase(k);
        }
        li.push_front({key, value});
        m[key] = li.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
