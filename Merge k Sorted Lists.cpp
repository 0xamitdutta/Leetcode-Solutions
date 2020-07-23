/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// TC - O(NlogN), SC - O(N) where N = total number of elements in all linked list
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

// TC - O(Nlogk), SC - O(1) where k = total number of linked list
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, decltype(&comp)> pq(comp);
        for(auto head : lists){
            if(head != NULL)
                pq.push(head);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(!pq.empty()){
            curr->next = pq.top();
            pq.pop();
            curr = curr->next;
            ListNode* next = curr->next;
            if(next != NULL)
                pq.push(next);
        }
        return dummy->next;
    }
    
    static bool comp(ListNode* p1, ListNode* p2){
        return p1->val > p2->val;
    }
};
