#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
};
struct node* root;
struct node* newnode(int key)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->data=key;
    t->right=NULL;
    t->left=NULL;
    t->height=1;
    return t;
};
int max(int a,int b)
{
    return (a>b)?a:b;
}
int height(struct node* t)
{
    if(t==NULL)
    {
        return 0;
    }
    else{
        return t->height;
    }
}
int balance(struct node* t)
{
    if(t==NULL)
    {
        return 0;
    }
    else{
        return height(t->left)-height(t->right);
    }
}
struct node* rightrotate(struct node *n)
{
    struct node *t,*x;
    x=n->left;
    t=x->right;
    x->right=n;
    n->left=t;
    n->height=1+max(height(n->left),height(n->right));
    x->height=1+max(height(x->left),height(x->right));
    return x;
};
struct node* leftrotate(struct node *n)
{
    struct node *t,*x;
    x=n->right;
    t=x->left;
    x->left=n;
    n->right=t;
    n->height=1+max(height(n->left),height(n->right));
    x->height=1+max(height(x->left),height(x->right));
    return x;
};
struct node* minvalue(struct node* curr)
{
    struct node* t;
    t=curr;
        while(t->left!=NULL)
        {
            t=t->left;
        }
        return t;
};
struct node *insert(struct node* n,int key)
{
    if(n==NULL)
    {
        return newnode(key);
    }
    else if (key<n->data)
    {
        n->left=insert(n->left,key);
    }
    else if(key>n->data)
    {
        n->right=insert(n->right,key);
    }
    else
    {
        return n;
    }
    n->height=1+max(height(n->left),height(n->right));
    int bal=balance(n);
    if(bal>1 && key<n->left->data)
    {
        return rightrotate(n);
    }
    else if(bal>1 && key>n->left->data)
    {
        n->left=leftrotate(n->left);
        return rightrotate(n);
    }
    else if(bal<-1 && key>n->right->data)
    {
        return leftrotate(n);
    }
    else if(bal<-1 && key<n->right->data)
    {
        n->right=rightrotate(n->right);
        return leftrotate(n);
    }
    return n;
};
struct node* delete(struct node* n,int key)
{
    if(n==NULL)
    {
        return n;
    }
    else if(key<n->data)
    {
        n->left=delete(n->left,key);
    }
    else if(key>n->data)
    {
        n->right=delete(n->right,key);
    }
    else
    {
        struct node *temp,*b;
        if((n->left==NULL)||(n->right==NULL))
        {
            temp=n->left ? n->left:n->right;
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
            b=minvalue(n->right);
            n->data=b->data;
            n->right=delete(n->right,b->data);
        }
    }
    if(n==NULL)
        return n;
    n->height=1+max(height(n->left),height(n->right));
    int bal=balance(n);
    if(bal>1 && balance(n->left)>=0)
    {
        return rightrotate(n);
    }
    else if(bal>1 && balance(n->left)<0)
    {
        n->left=leftrotate(n->left);
        return rightrotate(n);
    }
    else if(bal<-1 && balance(n->right)<=0)
    {
        return leftrotate(n);
    }
    else if(bal<-1 && balance(n->right)>0)
    {
        n->right=rightrotate(n->right);
        return leftrotate(n);
    }
    return n;
};
void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    int n,tem;
    while(1)
    {
        printf("1.to inert\n");
        printf("2.to delete\n");
        printf("3.to display\n");
        printf("4.to exit\n");
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
                root=delete(root,tem);
                break;
            case 3:
                preOrder(root);
                break;
            case 4:
                exit(0);
        }
    }
}
