#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int q[SIZE],front=1,rear=1;
void main()
{
void enqueue(int);
int dequeue(),opt,item,ans;
void display();
int search(int);
while(1)
{
printf("\n1.Insert \n2.Delete \n3.Display \n4.search \n5.exit \n");
printf("Your option\n");
scanf("%d",&opt);
switch(opt)
{
case 1:
printf("item to insert:");
scanf("%d",&item);
enqueue(item);
break;
case 2:
item=dequeue();
printf("Deleted Item %d=",item);
break;
case 3:
display();
break;
case 4:
printf("Item to search\n");
scanf("%d",&item);
ans=search(item);
if(ans==1)
printf("found\n");
else
printf("not found\n");
break;
case 5:exit(0);
}
}
}
void enqueue(int data){
int r1;
r1=(rear+1)%SIZE;
if(r1==front)
printf("Queue is full\n");
else
{
rear=r1;
q[rear]=data;
}
return;
}
int dequeue()
{
if(front==rear)
{
printf("Empty queue\n");
exit (1);
}
else
{
front=(front+1)%SIZE;
return q[front];
}
}
void display()
{
int f=front,r=rear;
while(f!=r)
{
f=(f+1)%SIZE;
printf("%d\n",q[f]);
}
return;
}
int search(int item)
{
int f=front,r=rear;
while(f!=rear)
{
f=(f+1)%SIZE;
if(q[f]==item)
return 1;
}
return 0;
}




