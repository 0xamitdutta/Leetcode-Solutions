/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        
        vector<int> v;
        ListNode *curr = head;
        while(curr != NULL){
            v.push_back(curr->val);
            curr = curr->next;
        }
        return constructBST(v, 0, v.size()-1);
    }
    
    TreeNode* constructBST(vector<int>& v, int low, int high){
        if(low > high)return NULL;
        
        int mid = low + (high-low)/2;
        TreeNode* root = new TreeNode(v[mid]);
        
        root->left = constructBST(v, low, mid-1);
        root->right = constructBST(v, mid+1, high);
        return root;
    }
};
