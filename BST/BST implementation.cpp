#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

struct node{
	node *left, *right;
	int val, height;
	node(int value)	{val=value; height=1; left=right=NULL;}
};

void update(node* &root){
	// update heights
	int hL=(root->left)?root->left->height:0, hR=(root->right)?root->right->height:0;
	root->height=1+((hL>hR)?hL:hR);	
}

node* rotate(node *root, int flag){ // flag=-1, left rotation; flag=+1, right rotation
	if(flag==-1){
		if(!root->right) return root;
		node* R=root->right, *RL=R->left;
		// rebuild links
		root->right=RL; R->left=root;
		update(root); update(R); // note the order
		return R;
	}
	if(flag==+1){
		if(!root->left) return root;
		node *L=root->left, *LR=L->right;
		// rebuild links
		root->left=LR; L->right=root;
		update(root); update(L); // note the order
		return L;
	}
}

void balance(node *&root){
	int hL=(root->left)?root->left->height:0, hR=(root->right)?root->right->height:0;
	if(hL-hR>1){ // LR or LL
		node* L=root->left;
		int hLL=(L->left)?L->left->height:0, hLR=(L->right)?L->right->height:0;
		if(hLL>hLR) { root=rotate(root, +1); } // LL
		else { root->left=rotate(L, -1); root=rotate(root, +1); } // LR
	}
	if(hR-hL>1){ // RL or RR
		node *R=root->right;
		int hRL=(R->left)?R->left->height:0, hRR=(R->right)?R->right->height:0;
		if(hRR>hRL) { root=rotate(root, -1); } // RR
		else { root->right=rotate(R,+1); root=rotate(root, -1); } // RL
	}
}

void insert(node* &root, int value){
	if(!root) {root=new node(value);}
	else if(root->val>value){
		if(!root->left){ node *tmp=new node(value); root->left=tmp; }
		else {insert(root->left, value);}
		update(root);
		balance(root);
	}	
	else if(root->val<value){
		if(!root->right) { node *tmp=new node(value); root->right=tmp; }
		else {insert(root->right,value);}
		update(root);
		balance(root);
	}
	else return ; // not trying multiset rightnow
}

void preorder(node* root, vector<node*> &ret){
	ret.push_back(root);
	if(root->left) preorder(root->left, ret);
	if(root->right) preorder(root->right, ret);
}

int main(){
	
	int arr[]={5,3,4,2,1,0,6};
	node* root=NULL;
	for(int i=0;i<sizeof(arr)/sizeof(int);i++){
		insert(root, arr[i]);
	}

	vector<node*> res;
	res.clear();	preorder(root, res);
	
	for(int i=0;i<res.size();i++){
		cout<<"value: "<<res[i]->val<<", height: "<<res[i]->height<<endl;
	}
	return 0;
}
