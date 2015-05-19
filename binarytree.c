#include<stdlib.h>
#include<stdio.h>

typedef struct TreeNode{
		struct TreeNode * left;
		struct TreeNode * right;
		int value;
}TreeNode;

typedef struct ListNode{
		struct ListNode * next;
		int value;
}ListNode;

void addListNode(ListNode *headnode, int value){
	if(headnode->value==NULL) {headnode->value=value; return;}
	ListNode *newnode=(ListNode*)malloc(sizeof(ListNode));
	newnode->value=value;
	newnode->next=NULL;
	while(headnode->next!=NULL){
			headnode=headnode->next;
	}
	headnode->next=newnode;
	printf("added listnode value %d\n",newnode->value);
	
}

void printList(ListNode *headnode){
		while(headnode!=NULL){
				printf("value is %d\n",headnode->value);
				headnode=headnode->next;
}

}
		
void TreeInorder(TreeNode * root, ListNode *headnode){
	TreeNode * cur=root;
	while(cur!=NULL){
		if(cur->left!=NULL){
			TreeNode* node=cur->left;	
			while(node->right!=NULL && node->right!=cur){
					node=node->right;
			}

			if(node->right==NULL){
					node->right=cur;
					cur=cur->left;
			}else if(node->right==cur){
					node->right=NULL;
					addListNode(headnode,cur->value);
					printf("visited %d\n",cur->value);
					cur=cur->right;
			}
		}
		else{
			addListNode(headnode,cur->value);
			printf("visited %d\n",cur->value);
			cur=cur->right;
		}


	}			

}


int main(){
	TreeNode * p[7];
	for (int i=0;i<7;i++){
		p[i]=(TreeNode*)malloc(sizeof(TreeNode));
		p[i]->value=i+10;
		p[i]->left=p[i]->right=NULL;
	}

	p[1]->left=p[0];
	p[1]->right=p[2];
	p[3]->left=p[1];
	p[3]->right=p[5];
	p[5]->left=p[4];
	p[5]->right=p[6];

	TreeNode * rootnode=p[3];
	ListNode * headnode=(ListNode*)malloc(sizeof(ListNode));
	headnode->next=NULL;
	headnode->value=NULL;
	TreeInorder(rootnode,headnode);
	printList(headnode);
}

