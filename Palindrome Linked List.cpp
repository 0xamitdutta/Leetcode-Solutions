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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverseList(slow);
        fast = head;
        while(slow) {
            if(fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};
