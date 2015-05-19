#include<stdlib.h>
#include<stdio.h>

typedef struct Node{
		int value;
		struct Node *next;
}Node;


void printList(Node * headnode){
		while(headnode!=NULL){
				printf("this value is %d\n",headnode->value);
				headnode=headnode->next;
		}
}


Node * constructList(int a[],int n){
		Node* headnode=NULL;
		Node* current=(Node *)malloc(sizeof(Node));
		headnode=current;
		headnode->value=a[0];
		for (int i=1;i<n;i++) {//1...4
			current->next=(Node *)malloc(sizeof(Node));
			current=current->next;
			current->value=i;
		}
		current->next=NULL;
		return headnode;
}

void insertHead(Node * headnode, int insert){
		Node * newnode=(Node*)malloc(sizeof(Node));
		newnode->value=headnode->value;
		newnode->next=headnode->next;
		headnode->value=insert;
		headnode->next=newnode;
}
void insertTail(Node * headnode, int insert){
		Node * newnode=(Node*)malloc(sizeof(Node));
		while(headnode->next!=NULL) headnode=headnode->next;
		headnode->next=newnode;//////// wrong first time!!cautious
		newnode->value=insert;
		newnode->next=NULL;
}

int listSize(Node *headnode){
		int size=0;
		while(headnode!=NULL) {
			headnode=headnode->next;
			size++;
		}
		return size;
}

void insertPos(Node *headnode, int pos,int value){// insert after position
		int length=listSize(headnode);
		if(pos==length) {
			insertTail(headnode,value);
			return ;
		}
		if(pos>length || pos<0) return;
		int tracer=0;
		while(tracer<pos){
				headnode=headnode->next;
				tracer++;
		}

		insertHead(headnode,value);
}	

void deletePos(Node *headnode, int n){ //delete the nth element
		int tracer=1;
		int length=listSize(headnode);
		if(n==1 ) return;
		Node* oldnode=NULL;
		while(tracer++<n){
				oldnode=headnode;
				headnode=headnode->next;
		}
		oldnode->next=headnode->next;
		free(headnode);
}


int main (){
		int a[] ={0,1,2,3,4};
		Node * headnode=constructList(a,5);
		printList(headnode);
		insertHead(headnode,-1);
		printList(headnode);
		insertTail(headnode,5);
		printList(headnode);
		insertPos(headnode,0,-3);
		printList(headnode);
		insertPos(headnode,1,-2);
		printList(headnode);
		insertPos(headnode,9,6);
		printList(headnode);
		deletePos(headnode,2);
		printList(headnode);
}
