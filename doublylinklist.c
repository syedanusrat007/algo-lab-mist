#include <stdio.h>
#include <stdlib.h>

struct node{

  int data;
  struct node *next;
  struct node *prev;
};


void insetfirst(struct node *head,int data)
{
    struct node *newitem,*tmp,*last;
    newitem=(struct node *)malloc(sizeof(struct node *));
    newitem->data=data;
    if(head==NULL)
    {
        head=newitem;
        head->next=NULL;
        head->prev=NULL;
        last=head;
    }
    else{
        tmp=newitem;
        tmp->prev=NULL;
        tmp->next=head;
        head->prev=tmp;
        head=tmp;
    }
}
void print(struct node *head)
{
    if(head==NULL)
    {
        return;
    }
    struct node *cur=head;
    while(cur!=NULL){
    printf("%d ",cur->data);
    cur=cur->next;
    }

}

int main()
{
    struct node *start,*temp;
    start = ( struct node *)malloc(sizeof( struct node));
    temp = start;
    temp -> next = NULL;
    temp -> prev = NULL;
    printf("1.insert 1st 2.insert last 3.insert mid 4.delete 5.find 6.print\n");
    int a;

    while(1)
    {
        scanf("%d",&a);
        if(a==1)
        {
            int b;
            scanf("%d",&b);
            insetfirst( start,b);

        }
       /*else if(a==2)
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

            delete();
        }
        else if(a==5)
        {
            int b;
            scanf("%d",&b);
            find(b);
        }*/
        else if(a==6)
        {
          print(start);
        }

    }
    return 0;
}

