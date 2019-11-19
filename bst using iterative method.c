//BST and all the operations on BST
#include<stdio.h>
#include<stdlib.h>
int in[100];
int i=0;
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* root;

int insert(int a)
{
	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=a;
	temp->left=NULL;
	temp->right=NULL;
	p=root;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		while(1)
		{
			if(temp->data>p->data)
			{
				if(p->right==NULL)
				{
					p->right=temp;
					break;
				}
				p=p->right;
			}
			else
			{
				if(p->left==NULL)
				{
					p->left=temp;
					break;
				}
				p=p->left;
			}
		}
	}
}
int del(int a)
{
	struct node *p,*t;
	t=root;
	while(t->data!=a)
	{
		p=t;
		if(t->data<a)
		{
			t=t->right;
		}
		else
		{
			t=t->left;
		}
		if(t==NULL)
		{
			break;
		}
	}
	if(t==NULL)
	{
		printf("the element is not prsent\n");
	}
	else
	{
		if(t->right==NULL&&t->left==NULL)
	    {
		    if(t=p->right)
		    {
		    	p->right=NULL;
		    	free(t);
		    }
		    else
		    {
		    	p->left=NULL;
		    	free(t);
		    }
	    }
	    else if(t->right!=NULL&&t->left!=NULL)
	    {
	    	struct node *x,*y;
	    	x=t->left;
	    	if (x->right!=NULL)
	    	{
	    		while(x->right)
	    		{
	    			y=x;
	    			x=x->right;
	    		}
	    		if (x->left!=NULL)
	    		{
	    			y->right=x->left;
	    			x->left=NULL;
	    			t->data=x->data;
	    			free(x);
	    		}
	    		else
	    		{
	    			t->data=x->data;
	    		    y->right=NULL;
	    		    free(x);
	    		}
	    	}
	    	else
	    	{
	    		if (p->right->data==a)
	    		{
	    			p->right=x;
	    			x->right=t->right;
	    		}
	    		else
	    		{
	    			p->left=x;
	    			x->right=t->right;
	    		}
	    		t->left=NULL;
	    		t->right=NULL;
	    		free(t);
	    	}
	    }
	    else if(t->right!=NULL||t->left!=NULL)
	    {
	    	if(t=p->right)
	    	{
	    		if(t->left!=NULL)
	    		{
	    			p->right=t->left;
	    			t->left=NULL;
	    			free(t);
	    		}
	    		else
	    		{
	    			p->right=t->right;
	    			t->right=NULL;
	    			free(t);
	    		}
	    	}
	    	else
	    	{
	    		if(t->left!=NULL)
	    		{
	    			p->left=t->left;
	    			t->left=NULL;
	    			free(t);
	    		}
	    		else
	    		{
	    			p->left=t->right;
	    			t->right=NULL;
	    			free(t);
	    		}
	    	}
	    }
	}
}
int max()
{
	struct node *p;
	p=root;
	if(p==NULL)
	{
		printf("there are no elements in the BST\n");
	}
	else
	{
		while(p->right!=NULL)
		{
			p=p->right;
		}
		printf("the maximum element is %d\n",p->data);
	}
}
int min()
{
	struct node *p;
	p=root;
	if(p==NULL)
	{
		printf("there are no elements in the BST\n");
	}
	else
	{
		while(p->left!=NULL)
		{
			p=p->left;
		}
		printf("the minimum element is %d\n",p->data);
	}
}
int display(struct node *p)
{
	if(p==NULL)
	{
		printf("there are no elements in the BST\n");
	}
	else
	{
		printf("%d ",p->data);
		if(p->left!=NULL)
		{
			display(p->left);
		}
		if(p->right!=NULL)
		{
			display(p->right);
		}
	}
}
int search(int a)
{
	struct node *p;
	p=root;
	while(1)
	{
		if(p==NULL)
		{
			printf("the required element is not present\n");
			break;
		}
		else
		{
			if(p->data<a)
			{
				p=p->right;
			}
			else if(p->data>a)
			{
				p=p->left;
			}
			else
			{
				printf("the element is present in the BST\n");
				break;
			}
		}
	}
}
int inorder(struct node *p)
{
	if(p==NULL)
	{
		printf("there are no elements in the BST\n");
	}
	else
	{
		if(p->left!=NULL)
		{
			inorder(p->left);
		}
		in[i]=p->data;
		i++;
		if(p->right!=NULL)
		{
			inorder(p->right);
		}
	}
}
int pre(int a)
{
	inorder(root);
	struct node *p;
	p=root;
	int k=0;
	while(a>in[k])
	{
		k++;
	}
	if(k==0)
	{
		printf("there is no predecessor for %d\n",a);
	}
	else
	{
		printf("the predecessor for %d is %d\n",a,in[k-1]);
	}
}
int suc(int a)
{
	inorder(root);
	struct node *p;
	p=root;
	int k=0;
	while(a>in[k])
	{
		k++;
	}
	printf("the successor for %d is %d\n",a,in[k]);
}
int main()
{
	int num,n1,n2,n3,n4,n5;
	while(1)
	{
		printf("\n");
		printf("1.for insert\n");
	    printf("2.to search\n");
	    printf("3.to find maximum\n");
	    printf("4.to find minimum\n");
	    printf("5.for predecessor\n");
	    printf("6.for successor\n");
	    printf("7.to delete\n");
	    printf("8.to display in preorder way\n");
	    printf("9.to quit\n");
	    printf("now enter your choice :");
	    scanf("%d",&num);
	    switch(num)
	    {
	    	case 1:
	    	printf("enter the number that is needed to be added :");
	    	scanf("%d",&n1);
	    	insert(n1);
	    	break;
	    	case 2:
	    	printf("enter the number that is needed to be searched :");
	    	scanf("%d",&n2);
	    	search(n2);
	    	break;
	    	case 3:
	    	max();
	    	break;
	    	case 4:
	    	min();
	    	break;
	    	case 5:
	    	printf("enter the no for which we have to find predecessor :");
	    	scanf("%d",&n3);
	    	pre(n3);
	    	break;
	    	case 6:
	    	printf("enter the no for which we have to find successor :");
	    	scanf("%d",&n4);
	    	suc(n4);
	    	break;
	    	case 7:
	    	printf("enter the number that is needed to be deleted :");
	    	scanf("%d",&n5);
	    	del(n5);
	    	break;
	    	case 8:
	    	printf("the order of elements in preoredr is : ");
	    	display(root);
	    	break;
	    	case 9:
	    	exit(0);
	    	break;
	    	default:
	    	printf("invalid input\n");
	    }
	}
}
