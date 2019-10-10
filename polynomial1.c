#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define null 0



struct node{
int pow;
int co;
struct node *link;
};
typedef struct node * NODE;
NODE poly1,poly2,poly;


void read(NODE x)
  {     NODE ptr1,ptr2;
      ptr1=x;
      poly1=ptr1;

      int n,i,c,p;
      printf("enter number of terms\n");
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {


          printf("enter coefficient\n");
          scanf("%d",&c);
          printf("enter power\n");
          scanf("%d",&p);
          if(ptr1==null)
          {
             ptr1->co=c;
             ptr1->pow=p;

          }
          else
        {
                while(ptr1->link!=null)
                {
                ptr1->link=(NODE)malloc(sizeof(struct node));
                ptr1=ptr1->link;

                }
               ptr1->co=c;
             ptr1->pow=p;

          }



    }}
  void display(NODE x)
  {
      NODE t;
      t=x;
      while(t->link!=null)
      {
          printf("%dX^%d",t->co,t->pow);
          t=t->link;
      }
      t=poly2;
      while(t->link!=null)
      {
          printf("%dX^%d",t->co,t->pow);
          t=t->link;
      }

  }
  void main()
  {   printf("for polynomial 1\n");
      read(poly1);
      printf("for polynomial 2\n");
      read(poly2);
      printf("polynomial 1\n");
      display(poly1);
      printf("polynomial 2\n");
      display(poly2);

  }
