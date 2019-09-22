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




void insert()
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

struct node * mid(struct node *i,struct node *j)
{   if(i==null)
return NULL;

struct node * slow=i;
struct node * fast=i->right;
while(fast!=j){
    fast=fast->right;
    if(fast!=j){
        slow=slow->right;
        fast=fast->right;
    }
}
return slow;
}
struct node * search()
{    int ch;
    struct node *i=root,*j=null;
    struct node *middle;
    printf("enter value\n");
    scanf("%d",&ch);
    do{
        middle=mid(i,j);

    if(middle==null)
        return null;
    if(middle->data==ch)
      return middle;
     else if(middle->data<ch)
        i=middle->right;
     else
        j=middle;
}while(j==null || j!=i);
return null;


}
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
void main()
{
    struct node *l;
    int c;
    while(1)
{
    printf("\n1.insert\n");
    printf("2.display\n");
    printf("3.search\n");
    printf("4.exit\n");
    printf("enter the option\n");
    scanf("%d",&c);
    switch(c)
    {

        case 1:
        insert();
        break;
        case 2:
        display();
        break;
        case 3:
        l=search();
        if(l!=null)
            printf("found");
        else
            printf("not found");
        break;
        case 4:
        exit(0);
        break;
        default:
        printf("invalid");}
}}

