/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        // Create copy nodes within hashmap
        Node* curr = head;
        unordered_map<Node*, Node*> m;
        while(curr != NULL){
            m[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        // Connext next and random within hashmap itself
        curr = head;
        while(curr != NULL){
            m[curr]->next = m[curr->next];
            m[curr]->random = m[curr->random];
            curr = curr->next;
        }
        return m[head];
    }
};
