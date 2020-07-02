// We're using a vector just for getRandom() else unordered_set/map is sufficient for insert/delete

class RandomizedSet {
private:
    vector<int> v;
    unordered_map<int, int> m;

public:
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) != m.end())
            return false;
        
        v.push_back(val);
        m[val] = v.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    // Swap the given val with the last one
    bool remove(int val) {
        if(m.find(val) == m.end())
            return false;
        
        int last = v.back();
        
        // Update the position of last val with current val
        m[last] = m[val];
        
        // Swap the position of last val and current val in vector
        int i = m[val], j = v.size()-1; 
        swap(v[i], v[j]);
        
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    // Use rand() func and to get rand to work in a range [min, max] use rand()%(max-min+1)+min
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
