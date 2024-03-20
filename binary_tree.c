#include <stdio.h>
#include <stdlib.h>

struct bitree
{
	int data;
	struct bitree* left;
	struct bitree* right;
};

typedef struct bitree node;

node* create(int data)
{
	node* newNode=(node*)(malloc(sizeof(node)));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return(newNode);
}

void createTree(node* parent)
{
	int data,flag,parentKey;
	char child;
	printf("Do you want to insert the node at the left child or right child? Press L for left and R for right: ");
	scanf("%c",&child);
	printf("Enter the value of node: ");
	scanf("%d",&data);
	node* newnode=create(data);
	if(child=='R')
	parent->right=newnode;
	else
	parent->left=newnode;
	printf("Do you want to insert another node? Press 1 for yes and 0 for no: ");
	scanf("%d",&flag);
	if(flag==1)
	createTree(newnode);

}
int main()
{
	int data,flag;
	printf("Enter the value of root node:");
	scanf("%d",&data);
	node* root=create(data);
	printf("Do you want to insert another node? Press 1 for yes and 0 for no: ");
	scanf("%d",&flag);
	if(flag==1)
	createTree(root);
	//node* parent=root;
	
}