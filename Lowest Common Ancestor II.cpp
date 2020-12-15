/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
        if(!root || !A || !B) return NULL;
        
        unordered_set<ParentTreeNode*> s;
        ParentTreeNode* node = A;
        while(node != NULL){
            s.insert(node);
            node = node->parent;
        }
        
        node = B;
        while(node != NULL){
            if(s.count(node)) break;
            node = node->parent;
        }
        return node;
    }
};
