/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<>> pq;
        for(int i = 0; i < lists.size(); i++){
            ListNode* head = lists[i];
            while(head != NULL){
                pq.push(head->val);
                head = head->next;
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(!pq.empty()){
            curr->next = new ListNode(pq.top());
            pq.pop();
            curr = curr->next;
        }
        return dummy->next;
    }
};
