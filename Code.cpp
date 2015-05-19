//Construction of LinkedList
//Construction of BST

//Successor


  BSTNode(const Data & d) : data(d) {
    left = right = parent = 0;
  }

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.

  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */
  BSTNode<Data>* successor() {
    BSTNode<Data>* current = this;
    
    /* first check to see if the successor is in the right child */
    if (this->right != NULL)
    {
      //RM printf("Right node exists and is %d, so setting to current.\n",current->right->data);
      // move right 1
      current = current->right;
      // then move left as far as you can
      while (current->left != NULL )
      {
      //RM printf("Left node  exists and is %d, so setting to current.\n",current->left->data);
        current = current->left;
      }
      return current;
    }
    /* alternativly the next node could be in a parent */
    BSTNode<Data>* parent = this->parent;
    // look for a parent that matches
    while (current != NULL && parent != NULL && parent->right == current )
    {
      //RM printf("Parent exists and is %d, current is the right node of it and is %d\n",parent->data,current->data);
      current = parent;
      parent = current->parent;
      //RM printf("Setting current to %d, and parent to the new current's parent %d\n",current->data,parent->data);
    }
    return parent;
  }

}; 


//Linked list to BST
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int length=0;
        ListNode *counter=head;
        while(counter!=nullptr){
            length++;
            counter=counter->next;
        }
        
        return sort(head,length);
    }
    
    TreeNode *sort(ListNode *head,int length){
        if(length==0) return nullptr;
        if(length==1) return new TreeNode(head->val);
        int mid=length/2;
        
        TreeNode *root=new TreeNode(get_nth(head,mid)->val);
        root->left=sort(head,mid);
        root->right=sort(get_nth(head,mid+1),length-mid-1);  //cautious!!!
        return root;
    }
    
    ListNode * get_nth(ListNode *head,int n){
        while(n>0){
            head=head->next;
            n--;
        }
        return head;
    }
};






//array to BST
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sort(num.begin(),num.end());
    }
    
    template<typename ITER>
    TreeNode *sort(ITER first,ITER last){
        if(first==last) return nullptr; //cautious
        
        ITER mid=first+(last-first)/2;
        TreeNode *root=new TreeNode(*mid);
        root->left=sort(first,mid);
        root->right=sort(mid+1,last);
        return root;
    }
};

//BST to linked list
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


//BST to array (trivial)





//BST iteration (stack+morris+stackinC)

Stack:
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode * cur=root;
        vector<int> result;
        stack<TreeNode*> stk;
        while(!stk.empty() ||cur!=nullptr){
            if(cur!=nullptr){
                stk.push(cur);
                cur=cur->left;
            }else{
                if(!stk.empty()){ //
                result.push_back(stk.top()->val);
                cur=stk.top()->right;
                stk.pop();
                }//
            }
        }
   
        return result;
    }
};


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode * cur=root;
        vector<int> result;
        stack<TreeNode*> stk;
        while(!stk.empty() ||cur!=nullptr){
            if(cur->left!=nullptr){  //try go to left, if can, mark self then go left;
                stk.push(cur);
                cur=cur->left;
            }else{ //can't go to left, then should consider going to right
                result.push_back(cur->val); //before going to right, visit self
                if(cur->right!=nullptr) cur=cur->right; //has right, go right
                else{ //if doesn't has right, then successor should be in the stack (even according to MORRIS)
                cur=cur->right;
					while(cur==nullptr){ //right doesn't find, then find successor in the stack, do the same
						if(stk.empty()) break; //if right isn't found, and 
						result.push_back(stk.top()->val);
						cur=stk.top()->right;
						stk.pop();
					}
                }

            }
        }
        return result;
    }
};






morris:
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode * cur=root;
        vector<int> result;
        while(cur!=nullptr){
            if(cur->left!=nullptr){
                TreeNode * Node=cur->left;
                while(Node->right!=nullptr && Node->right!=cur)
                    Node=Node->right;
                    
                if(Node->right==cur) {
                    Node->right=nullptr;
                    result.push_back(cur->val);
                    cur=cur->right;
                }else {
                    Node->right=cur;
                    cur=cur->left;
                }
            }else{
                result.push_back(cur->val);
                cur=cur->right;
            }
        }
        return result;
    }
};

//strSTR
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        char * pointer=haystack;
        char *strpointer=needle;
        char * firstoccur=nullptr;
        
        if(*pointer=='\0') {
           if(*strpointer=='\0') return pointer;//Cautious!!!
            return nullptr;
        }
        if(*strpointer=='\0')
            return pointer;
        
        while(*pointer!='\0'){
            firstoccur=pointer;
            while(*strpointer==*pointer){
                if(*(strpointer+1)=='\0') return firstoccur;
                if(*(pointer+1)=='\0') return nullptr;
                strpointer++;
                pointer++;
            }
            pointer=firstoccur+1;
            strpointer=needle;
            firstoccur=nullptr;
        }
        return nullptr;
    }
};

//missing element in array
//duplicate element in array
#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>

void findelement(int a[],int n){
		int * first=a;
		int * last=a+n;
		int *mid=0;
		int value;
		if(n==0) return;
		if(a[n-1]==(a[0]+n-1)) return;// missing something
		if(a[n-1]!=(a[0]+n)) return; //mising more than one;
		last--;
		
		while(first!=last){
			
			mid=first+(last-first)/2;
			value=(last-a+first-a+a[0]+a[0])/2;
//			printf("the mid value is :%d, the value is :%d\n",*mid,value);
//			system("read");
			if(value>=*mid) first=++mid;
			else last=mid;
				
		}


		printf("the first missing value should be %d\n",(*first-1));
}

void findduplicate(int a[], int n){
		int * first=a;
		int * last=a+n;
		int * mid=0;
		int value;
		if (n==0) return;
		if(a[n-1]==(a[0]+n-1)) return;
		last--;
		while(first!=last){
			mid=first+(last-first)/2;
			value=(last-a+first-a+a[0]+a[0])/2;

			if(value<=*mid) first=mid+1;
			else   last=mid;
		}
		printf("the first duplicate is %d\n",*first);

}
int main(){
		int pass[]={1,2,3,5,6,7};
		findelement(pass,6);
		int duplicate[]={1,2,3,3,4,5};
		findduplicate(duplicate,6);


}


//recover BST

