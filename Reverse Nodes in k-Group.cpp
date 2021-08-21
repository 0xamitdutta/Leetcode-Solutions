/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int K) {
        ListNode* node = head;
        int count = 0;
        while(count < K) {
            if(!node) return head;
            node = node->next;
            count++;
        }
        
        ListNode* prev = reverseKGroup(node, K);
        while(count > 0) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
            count--;
        }
        return prev;
    }
};
