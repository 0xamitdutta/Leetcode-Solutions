/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            curr->next = new ListNode(sum%10);
            carry = sum/10;
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            int sum = l1->val + carry;
            curr->next = new ListNode(sum%10);
            carry = sum/10;
            curr = curr->next;
            l1 = l1->next;
        }
        while(l2 != NULL){
            int sum = l2->val + carry;
            curr->next = new ListNode(sum%10);
            carry = sum/10;
            curr = curr->next;
            l2 = l2->next;
        }
        if(carry > 0)
            curr->next = new ListNode(carry);
        return dummy->next;
    }
};
