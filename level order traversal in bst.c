#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int l;
struct node
{
    int data;
    struct node *left,*right;
};
struct node* root;
struct node* newnode(int key)
{
    struct node* n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=key;
    n->left=NULL;
    n->right=NULL;
    return n;
};
struct node* minvalue(struct node* n)
{
    struct node* temp;
    temp=n;
    while(temp->left)
    {
        temp=temp->left;
    }
    return temp;
};
struct node* insert(struct node* n,int k)
{
    if(n==NULL)
    {
        return newnode(k);
    }
    else if(k<n->data)
    {
        n->left=insert(n->left,k);
    }
    else if(k>n->data)
    {
        n->right=insert(n->right,k);
    }
    else
    {
        return n;
    }
    return n;
};
struct node* dele(struct node* n,int k)
{
    if(n==NULL)
    {
        return n;
    }
    else if(k<n->data)
    {
        n->left=dele(n->left,k);
    }
    else if(k>n->data)
    {
        n->right=dele(n->right,k);
    }
    else
    {
        if((n->left==NULL)||(n->right==NULL))
        {
            struct node* temp;
            temp=n->left!=NULL ? n->left:n->right;
            if(temp==NULL)
            {
                temp=n;
                n=NULL;
                free(temp);
            }
            else
            {
                *n=*temp;
                free(temp);
            }
        }
        else
        {
            struct node* b;
            b=minvalue(n->right);
            n->data=b->data;
            n->right=dele(n->right,b->data);
        }
    }
    return n;
};
void preorder(struct node* n)
{
    if(n!=NULL)
    {
        printf("%d ",n->data);
        preorder(n->left);
        preorder(n->right);
    }
}
int levelorder(struct node* n,int a[],int i)
{
    if(n!=NULL && i<pow(2,l)-1)
    {
        a[2*(i+1)-1]=levelorder(n->left,a,2*(i+1)-1);
        a[2*(i+1)]=levelorder(n->right,a,2*(i+1));
    }
    else
    {
        return 0;
    }
    return n->data;
}
int maxDepth(struct node* node)
{
   if (node==NULL)
       return 0;
   else
   {
        int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);

       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
}
int main()
{
    int n,tem;
    int a[100];
    for(int i=0;i<100;i++)
    {
        a[i]=0;
    }
    while(1)
    {
        printf("1.to inert\n");
        printf("2.to delete\n");
        printf("3.to display\n");
        printf("4.to print in level order\n");
        printf("5.to exit\n");
        printf("enter your choice :");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("enter the value to insert : ");
                scanf("%d",&tem);
                root=insert(root,tem);
                break;
            case 2:
                printf("enter the value to be deleted :");
                scanf("%d",&tem);
                root=dele(root,tem);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                l=maxDepth(root);
                a[0]=levelorder(root,a,0);
                for(int i=0;i<pow(2,l)-1;i++)
                {
                    printf("%d ",a[i]);
                }
                printf("\n");
                break;
            case 5:
                exit(0);
        }
    }
}
