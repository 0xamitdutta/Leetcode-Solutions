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

#include <bits/stdc++.h>
using namespace std;

class ListNode {
    int val;
    ListNode *next, *prev;
    
    ListNode(int x) : val(x), next(NULL), prev(NULL) {}
};

class LRUCache {
private:
    int size, cap;
    ListNode *head = new ListNode(0), *tail = new ListNode(0);
    
    void add(ListNode* node) {
        ListNode *next = head->next;
        head->next = node;
        node->next = next;
        node->prev = head;
        next->prev = node;
    }
    
    void update (ListNode* node) {
        remove(node);
        add(node);
    }
    
    void remove (ListNode* node) {
        ListNode *prev = node->prev, *next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    
    void pop_back() {
        ListNode *node = tail->prev;
        remove(node);
        m.erase(node->val);
        delete node;
    }
public:
    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
    }
    
    /* Check 2 things here
    1. If value exists update node
    2. If value doesn't exist add node but check size
    */
    int getValue(int key) {
        if(m.count(key)) {
            update(m[key]);
            return m[key]->val;
        } 
        addKey(key);
        return m[key]->val;
    }
    
    void addKey(int key) {
        ListNode *node = new ListNode(key);
        m[key] = node;
        add(node);
        size++;
        if(size > cap) {
            pop_back();
            size--;
        }
    }
};

int main() {
    LRUCache *lru = new LRUCache(5);
    int a = lru->getValue(3);
    return 0;
}

