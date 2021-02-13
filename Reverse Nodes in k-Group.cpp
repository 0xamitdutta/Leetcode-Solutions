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
 
// Prerequisite Reverse Linked List II
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k == 1) return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        
        int i = 0;
        while(head != NULL){
            i++;
            if(i%k == 0){
                prev = reverse(prev, k);
                head = prev->next;
            }
            else
                head = head->next;
        }
        return dummy->next;
    }
    
    ListNode* reverse(ListNode* prev, int k){
        ListNode *curr = prev->next, *then = curr->next;
        for(int i = 1; i < k; i++){
            curr->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = curr->next;
        }
        return curr;
    }
};
