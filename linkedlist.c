#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define null 0
void insert();
void delete();
void display();
int length();
struct node reverse(struct node *p);

struct node{
int data;
struct node *link;
};
struct node *root;

void main()
{

    int c;
    while(1)
    {
    printf("\n1.insert\n");
    printf("2.delete\n");
    printf("3.display\n");
    printf("4.reverse\n");
    printf("5.reverse k nodes\n");
    printf("6.exit\n");
    printf("enter the option\n");
    scanf("%d",&c);
    switch(c)
    {

        case 1:
        insert();
        break;
        case 2:
        delete();
        break;
        case 3:
        display();
        break;
        case 4:
        reverse(root);
        break;
        case 5:
        rev();
        break;
        case 6:
        exit(0);
        break;
        default:
        printf("invalid");
        }}}
void insert()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
     printf("enter value\n");
    scanf("%d",&temp->data);
    temp->link=null;
    if(root==null)
    {   root=temp;
        }
    else{
   struct node *p;
   p=root;
   while(p->link!=null)
   {
       p=p->link;

   }

    p->link=temp;

}}
void delete()
{
    struct node *t,*q;
    int loc,len,i=1;
    printf("enter location");
    scanf("%d",&loc);
    len=length();
    if(loc>len)
{
    printf("invalid\n");


}
   else if(loc==1)
{
    t=root;
    root=root->link;
    t->link=null;
    free(t);

}
else{
    t=root;
    while(i<loc-1)
{  i++;
t=t->link;
}
q=t->link;
t->link=q->link;
q->link=null;
free(q);

}

}

void display()
{   struct node *temp;


    if(root==null)
    {

        printf("no element\n");

    }
    else{
            temp=root;
        while(temp->link!=null)
    {
        printf("%d\t",temp->data);
        temp=temp->link;}
        printf("%d\t",temp->data);
        }}

    int length()
    {
        int c=0;
        struct node *temp;
        temp=root;
        while(temp->link!=null)
    {
    c++;
        temp=temp->link;

    }
    return c;
    }
     struct node reverse(struct node *p)
    {
        if(p->link==null)
        {

            root=p;
            return ;
        }
        reverse(p->link);
        struct node *q=p->link;
        q->link=p;
        p->link=null;

    }
    void rev()
    {int k,l,i=1;
        printf("enter the number of nodes\n");
        scanf("%d",&k);
        l=length();
        if(k>l)
            printf("check \n");
        else{

            struct node *cur=root,*nex=null,*pre=null,*p=null;
            while(i<k)
            { cur=cur->link;
            i++;
            }
            p=cur->link;
            cur->link=null;
            cur=root;
            while(cur!=null)
            {  nex=cur->link;
                cur->link=pre;
                pre=cur;
                cur=nex;
                   }
                   root=pre;
                   cur=root;
                   while(cur->link!=null)
                   {
                       cur=cur->link;

                   }
            cur->link=p;

        }
    }

