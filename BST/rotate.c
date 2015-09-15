#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node *lc, *rc;
	int val;
	int h;
} node;

node* create_node(int val, int h) {
	node* ret = (node*) malloc(sizeof(node));
	ret->val = val;
	ret->h = h;	
	ret->lc = ret->rc = NULL;	
	return ret;
}
void delete_node(node* rt) {
	if (rt == NULL) return;
	if (rt->lc) delete_node(rt->lc); 
	if (rt->rc) delete_node(rt->rc); 
	free(rt);
}

void update_height(node* root){
	int hl = (root->lc ? root->lc->h : 0);
	int hr = (root->rc ? root->rc->h : 0);
	root->h = 1 + (hl > hr ? hl : hr);
}

void l_rotate(node** p_root) {
	node* r = (*p_root)->rc;
	node* rl = r->lc;
	(*p_root)->rc = rl;
	r->lc = (*p_root);
	update_height((*p_root));
	update_height(r);
	*(p_root) = r;
}

void preorder(node* root){
	if(!root) return; 
	printf("val: %d height: %d\n", root->val, root->h);
	preorder(root->lc);
	preorder(root->rc);
}

int main(){
	node* root = create_node(1,3);
	node* l = create_node(2,1);	
	node* r = create_node(3,2);
	node* rl = create_node(4,1);
	node* rr = create_node(5,1);
	root->lc = l;
	root->rc = r;
	r->lc = rl;
	r->rc = rr;
	puts("before l_rotation:");
	preorder(root);
	l_rotate(&root);

	puts("\nafter l_rotation");
	preorder(root);
	delete_node(root);
	return 0;	
}
