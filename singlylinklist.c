#include <stdio.h>
#include <stdlib.h>

struct node{

  int data;
  struct node *next;
};

struct node *head;

void insertfirst(int i)
{
    struct node *p=(struct node *)malloc(sizeof(struct node*));
    p->data=i;
    p->next=head->next;
    head->next=p;
}
void insertlast(int i)
{
     struct node *p=(struct node *)malloc(sizeof(struct node*));
    p->data=i;
    struct node *cur;
    cur=head;
    while(cur->next!=NULL)
          {
              cur=cur->next;
          }
          p->next=NULL;
          cur->next=p;
}
void insertmid(int i,int j)
{
    struct node *p=(struct node *)malloc(sizeof(struct node*));
    p->data=i;
    struct node *cur;
    cur=head;
    while(cur->data!=j)
    {
        cur=cur->next;
    }
    p->next=cur->next;
    cur->next=p;

}
void print(){
 if(head==NULL)
    return;
 struct node *cur=head->next;
 while(cur!=NULL)
 {
     printf("%d ",cur->data);
     cur=cur->next;

 }
 printf("\n");


}
int deletefirst()
{
    if(head==NULL)
        return;
    struct node *cur=head;
    head=head->next;
    free(cur);
}
int deletelast()
{
    if(head==NULL)
        return;
    struct node *cur=head;
     struct node *prev;
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    if(prev!=NULL)
    {
        prev->next=NULL;

    }
    free(cur);

}
int deletemid(int i)
{
    if(head==NULL)
        return;
    struct node *cur=head;
     struct node *prev;
      while(cur->data!=i)
    {
        prev=cur;
        cur=cur->next;
    }
    if(prev!=NULL)
    {
        prev->next=cur->next;
    }
    free(cur);
}



int main()
{
     head = (struct Node *)malloc(sizeof(struct Node*));
    head->next = NULL;
    printf("1.insert 1st 2.insert last 3.insert mid 4.delete 1st 5.delete last 6.delete mid 7.print\n");
    int a;

    while(1)
    {
        scanf("%d",&a);
        if(a==1)
        {
            int b;
            scanf("%d",&b);
            insertfirst( b);
        }
       else if(a==2)
        {
            int b;
            scanf("%d",&b);
            insertlast(b);
        }
         else if(a==3)
        {
            int b,c;
            scanf("%d%d",&b,&c);
            insertmid( b,c);
        }
      else if(a==4)
        {

            deletefirst();
        }
        else if(a==5)
        {

            deletelast();
        }
         else if(a==6)
        {
            int b;
            scanf("%d",&b);
            deletemid(b);
        }
        else if(a==7)
        {
          print();
        }

    }
    return 0;
}
