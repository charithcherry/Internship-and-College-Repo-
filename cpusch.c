#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct q{

int at,bt,st,wt,tat,n,ct;
}*p=NULL;

void main()
{   int n,i;
float avw=0,avt=0;
   printf("enter the number ");
   scanf("%d",&n);
   printf("-----------------------------------------------------------------------------------------------------------------\n");

   p=(struct q *)malloc(n*sizeof(struct q));

   for(i=0;i<n;i++)
   {
   printf("enter process number\n");
   scanf("%d",&(p+i)->n);
   printf("enter arrival time\n");
   scanf("%d",&(p+i)->at);
   printf("enter burst time\n");
   scanf("%d",&(p+i)->bt);
   printf("----------------------------------------------------------------------------------------------------------------\n");
   }
   (p+0)->st=0;
   (p+0)->wt=0;
  for(i=1;i<n;i++)
  {
      (p+i)->st=(p+(i-1))->st+(p+(i-1))->bt;
      (p+i)->wt=(p+i)->st-(p+i)->at;
      if((p+i)->wt<0)
      (p+i)->wt=0;
  }
for(i=0;i<n;i++)
{

    (p+i)->tat=(p+i)->bt+(p+i)->wt;
    (p+i)->ct=(p+i)->tat+(p+i)->at;

}
for(i=0;i<n;i++)
{


      avw+=(p+i)->wt;
      avt+=(p+i)->tat;
}


printf("process no\tarrival time\tburst time\tservice time\twaiting time\tturn around time\tcompletion time\n");
printf("---------------------------------------------------------------------------------------------------------------------\n");

for(i=0;i<n;i++)
{
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",(p+i)->n,(p+i)->at,(p+i)->bt,(p+i)->st,(p+i)->wt,(p+i)->tat,(p+i)->ct);
}

printf("average waiting = %.4f\n",(avw)/n);
printf("average tat = %.4f",(avt)/n);
getch();
}
