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
 
// O(n^2)
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return dfs(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
    
    int dfs(TreeNode* root, int sum, int& targetSum) {
        if(!root) return 0;
        
        sum += root->val;
        return (sum == targetSum ? 1 : 0) + dfs(root->left, sum, targetSum) + dfs(root->right, sum, targetSum);
    }
};

// O(n)
class Solution {
public:
    unordered_map<int, int> m;
    int pathSum(TreeNode* root, int targetSum) {
        m[0] = 1;
        int count = 0;
        dfs(root, 0, count, targetSum);
        return count;
    }
    
    void dfs(TreeNode* root, int sum, int& count, int targetSum) {
        if(!root) return;
        
        sum += root->val;
        if(m.count(sum - targetSum)) {
            count += m[sum - targetSum];
        }
        m[sum]++;
        dfs(root->left, sum, count, targetSum);
        dfs(root->right, sum, count, targetSum);
        m[sum]--;
    }
};

/* If you observe closely you'll find this question is very similar to "Subarray sum Equals K"
   Hence If you have to count number of subarrays think of "Prefix Sum"
*/
