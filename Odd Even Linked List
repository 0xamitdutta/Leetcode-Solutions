/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Space : O(n)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *p1 = head, *p2 = head->next;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int count = 0;
        while(p1){
            //cout << (++count) << " ";
            curr->next = new ListNode(p1->val);
            curr = curr->next;
            if(p1->next == NULL)
                break;
            p1 = p1->next->next;
        }
        while(p2){
            //cout << (++count) << " ";
            curr->next = new ListNode(p2->val);
            curr = curr->next;
            if(p2->next == NULL)
                break;
            p2 = p2->next->next;
        }
        return dummy->next;
    }
};

// Space : O(1)
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* ehead = even;
        while(even != NULL && even->next != NULL){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = ehead;
        return head;
    }
};
