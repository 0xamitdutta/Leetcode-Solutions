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
class Solution {
public:
    int ans = 0;
    int sumNumbers(TreeNode* root) {
        sumNumbersHelper(root, 0);
        return ans;
    }

    void sumNumbersHelper(TreeNode* root, int sum) {
        if(!root)
            return;
        sum += root->val;
        if(!root->left && !root->right) {
            ans += sum;
            return;
        }
        sumNumbersHelper(root->left, sum * 10);
        sumNumbersHelper(root->right, sum * 10);
    }
};

// Without using a global variable
class Solution {
private:
    int sumNumbersHelper(TreeNode* root, int sum) {
        if(!root) return 0;

        sum = sum * 10 + root->val;
        if(!root->left && !root->right)
            return sum;
        return sumNumbersHelper(root->left, sum) + sumNumbersHelper(root->right, sum);
        
    }
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbersHelper(root, 0);
    }
};
