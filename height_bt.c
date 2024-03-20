//height of a binary tree
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

void preorder(node* root)
{
    if(root==NULL)
    return;
    printf("%d->",root->data);
    preorder(root->left);
    preorder(root->right);
}

int height(node* current)
{
    if(current==NULL)
    return -1;
    
    int lheight=height(current->left);
    int rheight=height(current->right);

    if(lheight>=rheight)
    return(lheight+1);
    else
    return(rheight+1);
}

int main()
{
	int data,flag;
	//printf("Enter the value of root node:");
	//scanf("%d",&data);
	node* root=create(20);
    root->left=create(15);
    root->right=create(25);
    root->left->right=create(17);
    root->right->left=create(24);
    root->right->left->left=create(21);
    root->right->right=create(27);
    preorder(root);
    printf("\nHeight of the binary tree: %d",height(root));
}