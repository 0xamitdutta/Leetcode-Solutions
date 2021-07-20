// Inorder. PreOrder, PostOrder, LevelOrder, ZigZag, Vertical, Diagonal, Boundary**

// Diagonal
vector<int> diagonal(Node *root) {
   map<int, vector<int>> m;
   traverseDiagonal(root, 0, m);
   vector<int> res;
   for(auto p : m) {
       vector<int> ans = p.second;
       for(auto num : ans) {
           res.push_back(num);
       }
   }
   return res;
}

void traverseDiagonal(Node* root, int hd, map<int, vector<int>>& m) {
    if(!root) return;
    
    m[hd].push_back(root->data);
    traverseDiagonal(root->left, hd+1, m);
    traverseDiagonal(root->right, hd, m);
}

// Boundary
vector<int> res;
vector<int> printBoundary(struct node* root) {
    if (!root) return;
 
    res.psuh_back(root->data);
 
    // Print the left boundary in top-down manner.
    printBoundaryLeft(root->left);
 
    // Print all leaf nodes
    printLeaves(root->left);
    printLeaves(root->right);
 
    // Print the right boundary in bottom-up manner
    printBoundaryRight(root->right);
    
    return res;
}

void printBoundaryLeft(struct node* root) {
    if (!root) return;
 
    if (root->left) {
        res.psuh_back(root->data);
        printBoundaryLeft(root->left);
    }
    else if (root->right) {
        res.psuh_back(root->data);
        printBoundaryLeft(root->right);
    }
    // do nothing if it is a leaf node, this way we avoid duplicates in output
}

void printBoundaryRight(struct node* root) {
    if (!root) return;
 
    if (root->right) {
        printBoundaryRight(root->right);
        res.psuh_back(root->data);
    }
    else if (root->left) {
        printBoundaryRight(root->left);
        res.psuh_back(root->data);
    }
    // do nothing if it is a leaf node, this way we avoid duplicates in output
}

void printLeaves(struct node* root) {
    if (!root) return;
 
    printLeaves(root->left);
 
    // Print it if it is a leaf node
    if (!(root->left) && !(root->right))
         res.psuh_back(root->data);
 
    printLeaves(root->right);
}
