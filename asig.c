#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define s 10






void push(int *top1,int *top2,int a[])
{    int k,d;
    if(*top1==(s/2)-1 && *top2==(s/2))
    {
        printf("both stacks are full\n");
        return ;
    }
    printf("enter stack number\n");
    scanf("%d",&k);
    if(k==1)
{


    if(*top1==(s/2)-1)
    {

        printf("stack 1 full");
        return ;
    }
    else{

        printf("enter data\n");
        scanf("%d",&d);
        (*top1)++;
        a[*top1]=d;
    }
   }


else if(k==2){
    if(*top2==(s/2))
    {

        printf("stack 2 full\n");
        return ;
    }
    else{

        printf("enter data\n");
        scanf("%d",&d);
        (*top2)--;
        a[*top2]=d;
    }}

    else{
        printf("invalid choice\n");
    }
}

 void pop(int *top1,int *top2,int a[])
 {   int k;
     if(*top1==-1 && *top2==s)
    {
        printf("both stacks are empty\n");
        return;

    }
    printf("enter stack number\n");
    scanf("%d",&k);
    if(k==1)
{


    if(*top1==-1)
    {

        printf("stack 1 empty");
        return ;
    }
    else{

        printf("popped element is %d\n",a[*top1]);
        (*top1)--;

    }
   }


else if(k==2){
    if(*top2==s)
    {

        printf("stack 2 empty");
        return ;
    }
    else{

        printf("popped element is %d\n",a[*top2]);
        (*top2)++;

    }
    }
   else{
    printf("invalid stack\n");
    return;
   }
    }
void display(int *top1,int *top2,int a[])
{   int i;
    if(*top1==-1 && *top2==s)
    {
        printf("both stacks are empty\n");
        return;

    }

    if(*top1==-1 && *top2!=s)
    {
        printf("stack 1 is empty");
        printf("\nelements of stack 2 are\n");
        for(i=s-1;i>=*top2;i--)
        {

            printf("%d\t",a[i]);
        }
       return;
    }
    else if(*top1!=-1 && *top2==s)
    {
        printf("stack 2 is empty\n");
        printf("\nelements of stack 1 are\n");
        for(i=0;i<=*top1;i++)
        {

            printf("%d\t",a[i]);
        }
       return;
    }
    else
    {
        printf("\nelements of stack 1 are\n");
        for(i=0;i<=*top1;i++)
        {

            printf("%d\t",a[i]);

        }
        printf("\nelements of stack 2 are\n");
        for(i=s-1;i>=*top2;i--)
        {

            printf("%d\t",a[i]);
        }

    }



}





void main()
{
    int a[s];
    int top1=-1,top2=s;
     int c;
    while(1)
    {
    printf("\n1.push\n");
    printf("2.pop\n");
    printf("3.display\n");
    printf("4.exit\n");
    printf("enter the option\n");
    scanf("%d",&c);
    switch(c)
    {

        case 1:
        push(&top1,&top2,a);
        break;
        case 2:
        pop(&top1,&top2,a);
        break;
        case 3:
        display(&top1,&top2,a);
        break;
        case 4:
        exit(0);
        break;
        default:
        printf("invalid");
        }}


}
