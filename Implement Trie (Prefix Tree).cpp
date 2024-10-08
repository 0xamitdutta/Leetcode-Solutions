class Trie {
private:
    map<char, Trie*> children;
    bool isEnd;
public:
    Trie() {
        children = {};
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* node = this; // This is used to reference the object which is calling this function
        for(char c : word) {
            if(!node->children.count(c))
                node->children[c] = new Trie();
            node = node->children[c];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char c : word) {
            if(!node->children.count(c))
                return false;
            node = node->children[c];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char c : prefix) {
            if(!node->children.count(c))
                return false;
            node = node->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
