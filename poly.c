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
int pow;
struct node *link;
};
struct node *poly1,*poly2,*poly;


void main()
{

    int n,i,m;
    struct node *temp,*p;
    printf("enter number of  elements\n");
    scanf("%d",&n);
   for(i=1;i<=n;i++)
    {
    temp=(struct node *)malloc(sizeof(struct node));

     printf("enter power\n");
     scanf("%d",&temp->pow);
     printf("enter co efficient\n");
    scanf("%d",&temp->data);
    temp->link=null;
    if(poly1==null)
    {   poly1=temp;
        }
    else{

   p=poly1;
   while(p->link!=null)
   {
       p=p->link;

   }

    p->link=temp;
    }}
    printf("enter elements in poly 2\n");
    scanf("%d",&m);
     for(i=0;i<m;i++)
    {
    temp=(struct node *)malloc(sizeof(struct node));

     printf("enter power\n");
     scanf("%d",&temp->pow);
     printf("enter co efficient\n");
    scanf("%d",&temp->data);
    temp->link=null;
    if(poly2==null)
    {   poly2=temp;
        }
    else{

   p=poly2;
   while(p->link!=null)
   {
       p=p->link;

   }

    p->link=temp;
    }}
struct node *t,*y;

            t=poly1;
        while(t->link!=null)
    {
         printf("%d",t->data);
        printf("x^%d\t",t->pow);

        t=t->link;}

printf("%d",t->data);
        printf("x^%d\t",t->pow);
        printf("\n");
        t=poly2;
        while(t->link!=null)
    {
         printf("%d",t->data);
        printf("x^%d\t",t->pow);

        t=t->link;}

printf("%d",t->data);
        printf("x^%d\t",t->pow);


 while(poly1->link && poly2->link)
    {
        // If power of 1st polynomial is greater then 2nd, then store 1st as it is
        // and move its pointer
        if(poly1->pow > poly2->pow)
        {
            poly->pow = poly1->pow;
            poly->data = poly1->data;
            poly1 = poly1->link;
        }


        else if(poly1->pow < poly2->pow)
        {
            poly->pow = poly2->pow;
            poly->data = poly2->data;
            poly2 = poly2->link;
        }


        else
        {
            poly->pow = poly1->pow;
            poly->data = poly1->data+poly2->data;
            poly1 = poly1->link;
            poly2 = poly2->link;
        }


        poly->link = (struct Node *)malloc(sizeof(struct node));
        poly = poly->link;
        poly->link = NULL;
    }
while(poly1->link || poly2->link)
    {
        if(poly1->link)
        {
            poly->pow = poly1->pow;
            poly->data = poly1->data;
            poly1 = poly1->link;
        }
        if(poly2->link)
        {
            poly->pow = poly2->pow;
            poly->data = poly2->data;
            poly2 = poly2->link;
        }
        poly->link = (struct Node *)malloc(sizeof(struct node));
        poly = poly->link;
        poly->link = NULL;
    }



 t=poly;
        while(t->link!=null)
    {
         printf("%d",t->data);
        printf("x^%d\t",t->pow);

        t=t->link;}

printf("%d",t->data);
        printf("x^%d\t",t->pow);
        printf("\n");




}




