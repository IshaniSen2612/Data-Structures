//insertion and deletion in binary search tree
#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
};

typedef struct tree node;

node* create(int data)
{
    node* newnode=(node*) (malloc(sizeof(node)));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void insertNode(node* newnode, node* root)
{   

    if(newnode->data==root->data)
    {
        printf("Insertion not possible! Duplicate data.");
        return;
    }
	else if(newnode->data>root->data)
    {
        if(root->right==NULL)
        {
            root->right=newnode;
            return;
        }
        else
        insertNode(newnode,root->right);
    }
	else
    {
        if(root->left==NULL)
        {
            root->left=newnode;
            return;
        }
        else
        insertNode(newnode,root->left);
    }
}
void deleteNode(int key, node* root)
{

    if(root==NULL) //base case
    {   printf("Deletion unsuccessful!");
        return;
    }

    if(key>root->data) // If data to be deleted is greater than root's data, then search in the right subtree
    {
        deleteNode(key,root->right);
        return;
    }
    else if(key<root->data)// If data to be deleted is less than root's data, then search in the left subtree
    {
        deleteNode(key,root->left); 
         return;
    }
    else //(key==root->data) //root is the node to be deleted
    {
        node* temp=root;
        if(root->right==NULL && root->left==NULL) // case 1: node to be deleted has no children
        {
            node* temp=root;
            root=NULL;
            free(root);
            //return temp;
        }
        else if(root->right==NULL) // case 2: node to be deleted only has left child
        {
            // node* temp=root;
            root->data=root->left->data;
            root->left=NULL;
            free(root->left);
            //return(temp);
        }
        else if(root->left==NULL) // case 3: node to be deleted only has right child
        {
            // temp=root;
            root->data=root->right->data;
            root->right=NULL;
            free(root->right);
            //return(temp);
        }
        else                      //case 4: node to be deleted has both children
        {  
            node* succParent=root;
            node* succ=root->right;
            while(succ->left!=NULL)
            {
                succParent=succ;
                succ=succ->left;
            }
            root->data=succ->data;
            
            if(succParent==root)
                root->right=succ->right;
            else
                succParent->left=succ->right;
            free(succ);
        }
        return;
    }
}

void preTraverse(node* root)
{
    if(root==NULL)
    return;
    printf("%d->",root->data);
    preTraverse(root->left);
    preTraverse(root->right);
}

int main()
{
	int data,flag,key;
    //node* deleted=create(0);
	printf("Enter the value of root node:");
	scanf("%d",&data);
	node* root=create(data);
	printf("Do you want to insert another node? Press 1 for yes and 0 for no: ");
	scanf("%d",&flag);
	while(flag)
    {
        printf("Enter the value of node: ");
        scanf("%d",&data);
        node* newnode=create(data);
        insertNode(newnode,root);
        printf("Do you want to insert another node? Press 1 for yes and 0 for no: ");
	    scanf("%d",&flag);
    }
    printf("\nThe original binary tree in pre-order traversal is as follows:    ");
    preTraverse(root);
    printf("\nEnter the value to be deleted: ");
    scanf("%d",&key);
    deleteNode(key,root);
    //printf("Deleted value: %d", deleted->data);
    printf("\nThe modified binary tree in pre-order traversal is as follows:  ");
    preTraverse(root);
}
