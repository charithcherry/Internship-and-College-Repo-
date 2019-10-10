#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define null 0

struct node{

int data;
struct node *right;
struct node *left;

};
struct node *root=null;




void insertend()
{ struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("enter value\n");
    scanf("%d",&temp->data);
    temp->right=null;
    temp->left=null;
    if(root==null)
    {   root=temp;
        }
    else{
   struct node *p;
   p=root;
   while(p->right!=null)
   {
       p=p->right;

   }

    p->right=temp;
    temp->left=p;

}}


void display()
{  struct node *m;


    if(root==null)
    {

        printf("no element\n");

    }
    else{
        m=root;
        while(m->right!=null)
    {
       printf("%d\t",m->data);
        m=m->right;


    }
    printf("%d\t",m->data);


}}
void reverse()
{
    struct node *t,*n=null;

    t=root;
    while(t!=null)
    {

        n=t->left;
        t->left=t->right;
        t->right=n;
        t=t->left;
      }
      if(t!=null)
      {
          root=t->left;

      }

}
void insertbeg(){

struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("enter value\n");
    scanf("%d",&temp->data);
    temp->right=null;
    temp->left=null;
    if(root==null)
    {   root=temp;
        }
    else{
   struct node *p;
   p=root;
   temp->right=root;
   root=temp;


}}
void deleteend()
{

    struct node *cur,*prev;
if(root==null)

{
    printf("empty\n");
}
else{

    cur=root;
    while(cur->right!=null)

    {
        prev=cur;
        cur=cur->right;

    }

    prev->right=cur->right;

    free(cur);
     cur->left=null;

}
}
void deletebeg()
{

    struct node *cur,*prev;
if(root==null)

{
    printf("empty\n");
}
else{
cur=root;
    root=root->right;
    cur->right=null;
    free(cur);
    cur=null;

}}
void deletenode()
{
    struct node *cur,*prev;
    int d;
printf("enter the data to be removed\n");
scanf("%d",&d);
cur=root;
if(root==null)
{

    printf("empty\n");

}
else if(root->data==d)
{
    root=root->right;
    cur->right=null;
    free(cur);
    cur=null;


}
else if(root->right==null)
{

    if(root->data==d)
    {
        free(cur);
        cur=null;

    }
    else{
        printf("not found\n");
    }
}
else
{


while(cur!=null)
{

    if(cur->data==d)
    {
        break;


    }

    prev=cur;
    cur=cur->right;

}

if(cur==null)
{

    printf("not found\n");
}
else{

    if(cur->right!=null)
    {


prev->right=cur->right;
    cur->right->left=prev;
    cur->right=null;
    cur->left=null;
    free(cur);
    cur=null;
}
else{


    cur->right=null;
    cur->left=null;
    prev->right=null;
    free(cur);
    cur=null;

}


}

}
}
void main()
{

    int c;
    while(1)
{
    printf("\n1.insert at end\n");
    printf("2.reverse\n");
    printf("3.insert at beginning \n");
    printf("4.display\n");
    printf("5.exit\n");
    printf("6.delete at end\n");
    printf("7.delete at beg\n");
    printf("8.delete the node\n");
    printf("enter the option\n");
    scanf("%d",&c);
    switch(c)
    {

        case 1:
        insertend();
        break;
        case 2:
        reverse();
        break;
        case 4:
        display();
        break;
        case 3:
            insertbeg();
            break;
        case 5:
        exit(0);
        case 6:
            deleteend();
            break;
        case 7:
            deletebeg();
        case 8:
            deletenode();
        break;
        default:
        printf("invalid");}
}}

