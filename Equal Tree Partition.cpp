/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: a TreeNode
     * @return: return a boolean
     */
    map<int, int> m;
    bool checkEqualTree(TreeNode *root) {
        int sum = getSum(root);
        if(sum == 0) return m[0] > 1;
        return sum % 2 == 0 && m[sum/2];
    }

    int getSum(TreeNode* root) {
        if(!root) return 0;
        int sum = root->val + getSum(root->left) + getSum(root->right);
        m[sum]++;
        return sum;
    }
};
