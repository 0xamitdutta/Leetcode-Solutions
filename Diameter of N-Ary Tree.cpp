struct TreeNode {
	int val;
	vector<TreeNode*> children;

	TreeNode(int x) : val(x) {}
};

class Solution {
public:
    int d = 0;
    int diameter(TreeNode* root) {
        if(!root) return 0;
        int max1 = 0, max2 = 0;
        for(auto node : root->children) {
            int len = diameter(node);
            if(len > max1) {
                max2 = max1;
                max1 = len;
            }
            else if(len > max2) {
                max2 = len;
            }
        }
        d = max(d, max1+max2);
        return max1 + 1;
    }
};
