// https://www.lintcode.com/problem/lowest-common-ancestor-ii/description

/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */

// O(N) space
class Solution {
public:
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * A, ParentTreeNode * B) {
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

// O(1) Space
class Solution {
public:
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * A, ParentTreeNode * B) {
        // Similar to Intersction of 2 Linked Lists. If A reaches NULL move it to B and if B reaches to NULL move it to A
        ParentTreeNode* a = A, *b = B;
        while(a != b) {
            a = a == NULL ? B : a->parent;
            b = b == NULL ? A : b->parent;
        }
        return a;
    }
};
