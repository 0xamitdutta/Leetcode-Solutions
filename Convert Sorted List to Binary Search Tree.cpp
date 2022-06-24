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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
// TC = O(nlogn)
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) {
            TreeNode* node = new TreeNode(head->val);
            return node;
        }
        
        ListNode* prev, *slow = head, *fast = head;
        while(slow && fast && fast->next) {
            prev = slow; 
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        TreeNode* node = new TreeNode(slow->val);
        node->left = sortedListToBST(head);
        node->right = sortedListToBST(slow->next);
        return node;
    }
};
 
// TC = O(n)
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }
        return sortedListToBSTHelper(nums, 0, nums.size()-1);
    }
    
    TreeNode* sortedListToBSTHelper(vector<int>& nums, int low, int high) {
        if(low > high) return NULL;
        
        int mid = (low + high)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = sortedListToBSTHelper(nums, low, mid-1);
        node->right = sortedListToBSTHelper(nums, mid+1, high);
        return node;
    }
};
