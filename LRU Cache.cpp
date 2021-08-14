class LRUCache {
    list<int> l;
    unordered_map<int, list<int>::iterator> hash;
    int size;
    public:
        LRUCache(int n);
        void addPage(int x);
};

LRUCache::LRUCache(int n) {
    size = n;
}

void LRUCache::addPage(int x) {
    if(!hash.count(x)) {
        if(l.size() == size) {
            int last = l.back(); l.pop_back();
            hash.erase(last);
        }
        l.push_front(x);
        hash[x] = l.begin();
        return;
    }

    l.erase(hash[x]);
    l.push_front(x);
    hash[x] = l.begin();
}
