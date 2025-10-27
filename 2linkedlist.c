//doubly linked list - insertion, deletion,search
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node * left, *right;//pointers
};
void main()
{
struct node* start=(struct node*)0;


struct node* insert(struct node*,int);
struct node* delete(struct node*,int);
struct node* search(struct node*,int);
void display(struct node*);
int item,opt;
while(1)
{
printf("\n1.insert\n2.delete\n3.display\n4.search\n5.Exit\n");
printf("your option :");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("item to insert :");
       scanf("%d",&item);
       start=insert(start,item);
       break;
case 2:printf("item to delete :");
       scanf("%d",&item);
       start=delete(start,item);
       break;
case 3:display(start);
        break; 
case 4:printf("item to search:");
        scanf("%d",&item);
    if (search(start,item)==(struct node*)0)
        printf(" data not found---\n");
    else
        printf("data found---\n");
        break;
case 5:exit(0);
}
}
    }
//function to insert
struct node * insert(struct node * s,int data)
{
struct node* t;
t=(struct node*)malloc(sizeof(struct node));
t->data=data;
t->left=(struct node *)0;
t->right=s;
if  (s!=0)
s->left=t;
return t;
}
//function to display
void display(struct node*s)
{
while (s!=0)
{
printf("%d\n",s->data);
s=s->right;
}
return;
}
//function to search
struct node* search(struct node*s,int data)
{
while (s!=0&&data!=s->data)
s=s->right;
return s;
}
//function to delete
struct node * delete(struct node *s,int data)
{
struct node* t;
t=search(s,data);
if(t==0)
printf("data not found\n");
else{ 
if (t->left==0)// first node
{
s=s->right;// move pointer to next node
if (t->right!=0)
s->left=0;
}
else 
{
t->left->right=t->right;
if(t->right!=0)
t->right->left=t->left;
}
free(t);
}

return s;
}

