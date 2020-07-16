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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1), *prev = dummy;
        dummy->next = head;
        
        for(int i = 1; i < m; i++)
            prev = prev->next;
        ListNode *curr = prev->next, *then = curr->next;
        //  All you're doing is inserting then between prev and prev.next
        for(int i = 1; i <= n-m; i++){
            curr->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = curr->next;
        }
        return dummy->next;
    }
};
// 1->2->3->4->5 prev = 1, curr = 2, then = 3
// first reversing : dummy->1 - 3 - 2 - 4 - 5; pre = 1, start = 2, then = 4
// second reversing: dummy->1 - 4 - 3 - 2 - 5; pre = 1, start = 2, then = 5 (finish)
