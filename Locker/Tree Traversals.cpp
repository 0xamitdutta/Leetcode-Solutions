#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorder(TreeNode* root){
	if(!root) return {};

	vector<int> res;
	stack<TreeNode*> stk;
	stk.push(root);
	while(!stk.empty()){
		root = stk.top();
		stk.pop();
		res.push_back(root->val);
		if(root->right) 
			stk.push(root->right);
		if(root->left) 
			stk.push(root->left);
	}
	return res;
}

vector<int> inorder(TreeNode* root){
	vector<int> res;
	stack<TreeNode*> stk;
	while(root != NULL || !stk.empty()){
		while(root != NULL){
			stk.push(root);
			root = root->left;
		}
		root = stk.top();
		stk.pop();
		res.push_back(root->val);
		root = root->right;
	}
}

vector<int> postorder(TreeNode* root){
	vector<int> res;
	stack<TreeNode*> stk;
	while(root != NULL || !stk.empty()){
		while(root != NULL){
			stk.push(root);
			root = root->left;
		}
		TreeNode* temp = stk.top()->right;
		if(temp == NULL){
			temp = stk.top();
			stk.pop();
			res.push_back(temp->val);
			while(!stk.empty() && stk.top()->right == temp){
				temp = stk.top();
				stk.pop();
				res.push_back(temp->val);
			}
		}
		else{
			root = temp;
		}
	}
}

// Recursive Inorder
void inorderRecursive(TreeNode* root) {
	if(!root) return;

	inorderRecursive(root->left);
	res.push_back(root->val);
	inorderRecursive(root->right); 
}


int main(){
	TreeNode* root = new TreeNode(5);
	return 0;
}
