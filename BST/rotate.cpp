#include <stdio.h>
struct node{
	node *lc, *rc;
	int val;
	int h;
	node(int V,int H){val=V,h=H;lc=NULL,rc=NULL;}
};

void update(node* root){
	int hl=(root->lc?root->lc->h:0);
	int hr=(root->rc?root->rc->h:0);
	root->h=1+(hl>hr?hl:hr);
}

void rotate(node* &root){ //only rotates left
	node* R=root->rc;
	node* RL=R->lc;
	root->rc=RL;
	R->lc=root;
	//update heights(bottom up)
	update(root); update(R);
	//swap root
	root=R;
}

void preorder(node* root){
	if(!root) return; 
	printf("val: %d height: %d\n",root->val,root->h);
	preorder(root->lc);
	preorder(root->rc);
}

int main(){
	node* root=new node(1,3);
	node* L=new node(2,1);	
	node* R=new node(3,2);
	node* RL=new node(4,1);
	node* RR=new node(5,1);
	root->lc=L; root->rc=R;
	R->lc=RL, R->rc=RR;
	puts("before rotation:");
	preorder(root);
	rotate(root);
	puts("after rotation");
	preorder(root);
	return 0;	
}
