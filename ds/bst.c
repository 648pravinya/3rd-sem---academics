#include<stdio.h>
#include<stdlib.h>
struct BST
{
	int data;
	struct BST*left;
	struct BST*right;
};
typedef struct BST NODE;
NODE*node;
NODE*createtree(NODE*node,int data)
{
	if(node==NULL)
	{
		NODE*temp;
		temp=(NODE*)malloc(sizeof(NODE));
		temp->data=data;
		temp->left=temp->right=NULL;
		return temp;
	}
	if(data<(node->data))
	{
		node->left=createtree(node->left,data);
	}
	else if(data>node->data)
	{
		node->right=createtree(node->right,data);
	}
	return node;
}
NODE*search(NODE*node,int data)
{
	if(node==NULL)
		printf("\nelement not found");
	else if(data<node->data)
	{
		node->left=search(node->left,data);
	}

	else if(data>node->data)
	{
		node->right=search(node->right,data);
	}
	else
		printf("element found is:%d",node->data);
	return node;
}
void inorder(NODE*node)
{
	if(node!=NULL)
	{
		inorder(node->left);
		inorder(node->right);
		printf("%d\t",node->data);
	}
}
void preorder(NODE*node)
{
	if(node!=NULL)
	{
		preorder(node->left);
                preorder(node->right);
		 printf("%d\t",node->data);
	}
}
void postorder(NODE*node)
{
	if(node!=NULL)
	{
		postorder(node->left);
		postorder(node->right);
		printf("%d\t",node->data);
	}
}
NODE*findMin(NODE*node)
{
	if(node==NULL)
	{
		return NULL;
	}
	if(node->left)
	return findMin(node->left);
	else
		return node;
}
NODE*del(NODE*node,int data)
{
	NODE*temp;
	if(node==NULL)
	{
		printf("\nelement not found");
	}
	else if(data<node->data)
	{
		node->right=del(node->right,data);
	}
	else
	{
		if(node->right&&node->left)
		{
			temp=findMin(node->right);
			node->data=temp->data;
			node->right=del(node->right,temp->data);
		}
		else
		{
			temp=node;
			if(node->left=NULL)
				node=node->right;
			else if(node->right==NULL)
				node=node->left;
			free(temp);
		}
	}
	return node;
}
void main()
{
	int data,ch,i,n;
	NODE*root=NULL;
	while(1)
	{
		printf("\n1.insertion in binary search tree");
		printf("\n2.search element in binary search tree");
		printf("\n3.delete element in binary search tree");
		printf("\n4.inorder\n5.preorder\n6.postorder\n7.exit");
		printf("\n enter your choice");scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("\nenter N value:");
			scanf("%d",&n);
			printf("\nenter the values to create BST like(6,9,5,2,8,15,24,14,7,8,5,2)\n");
			for(i=0;i<n;i++)
			{
				scanf("%d",&data);
				root=createtree(root,data);
			}
			break;
		case 2:
			printf("\nenter the element to search:");
			scanf("%d",&data);
			break;
		case 3:
			printf("\nenter the element to delete:");
                        scanf("%d",&data);
			root=del(root,data);
			break;
		case 4:
			printf("\ninorder traversal:\n");
			inorder(root);
			break;
		case 5:
			printf("\npreorder traversal:\n");
                        preorder(root);
                        break;
		case 6:
			printf("\npostorder traversal:\n");
                        postorder(root);
                        break;
		case 7:
			exit(0);
		default:
			printf("\nwrong option");
			break;
		}
	}
}






	


