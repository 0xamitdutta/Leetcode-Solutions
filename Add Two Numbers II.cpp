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
        
        stack<int> s1, s2;
        for(; l1; l1 = l1->next) s1.push(l1->val);
        for(; l2; l2 = l2->next) s2.push(l2->val);
        
        ListNode* head = NULL;
        int sum = 0, carry = 0;
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            sum += carry;
            ListNode* curr = new ListNode(sum%10);
            curr->next = head;
            head = curr;
            carry = sum/10;
            sum = 0;
        }
        if(carry){
            ListNode* curr = new ListNode(carry);
            curr->next = head;
            head = curr;
        }
        return head;
    }
};
