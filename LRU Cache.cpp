class Node {
public:
    int key, val;
    Node *next, *prev;
    
    Node(int x, int y) : key(x), val(y), prev(NULL), next(NULL) {}
};

class LRUCache {
private:
    int size, cap;
    Node *head = new Node(0, 0), *tail = new Node(0, 0);
    map<int, Node*> m;
    
    void add(Node* node) {
        Node *next = head->next;
        head->next = node;
        node->next = next;
        node->prev = head;
        next->prev = node;
    }
    
    void update(Node* node) {
        remove(node);
        add(node);
    }
    
    void remove(Node* node) {
        Node *prev = node->prev, *next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    
    void pop_back() {
        Node* node = tail->prev;
        remove(node);
        m.erase(node->key);
        delete node;
    }
public:
    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!m.count(key)) 
            return -1;
        update(m[key]); // Update its position and bring it at front
        return m[key]->val;
    }
    
    void put(int key, int value) {
        if(m.count(key)) {
            m[key]->val = value;
            update(m[key]);
        } else {
            Node *node = new Node(key, value);
            m[key] = node;
            add(node);
            size++;
            if(size > cap) {
                pop_back();
                size--;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
