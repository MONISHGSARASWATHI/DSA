
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
struct node
{
    int data;
    node * next;
};
typedef struct node NODE;
class linkedlist
{
    NODE * head=NULL;
    public:
void insertatbegin(int val)
{
    NODE* newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void insertatend(int val)
{
    NODE* tptr;
    NODE* newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=val;
    newnode->next=NULL;
     if(head==NULL)
        head=newnode;
     else
        {
            for(tptr=head;tptr->next!=NULL;tptr=tptr->next);
            tptr->next=newnode;
        }
}
void insertatsort(int val)
{
    NODE* tptr,*prev;
    NODE* newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    for(prev=NULL,tptr=head;tptr!=NULL;prev=tptr,tptr=tptr->next)
    {
        if(tptr->data > newnode->data)
            break;
    }
    if(tptr==head)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        prev->next=newnode;
        newnode->next=tptr;
    }
}
void reverse()
{
    NODE *prev=NULL,*cur=head,*fut=head->next;
    while(cur!=NULL)
    {
        fut=cur->next;
        cur->next=prev;
        prev=cur;
        cur=fut;
    }
    head=prev;
}
void display()
{
   NODE* tptr;
   if(head==NULL)
   {
       printf("The linked list in empty\n");
   }
   else
   {
       printf("The values are:");
       for( tptr=head;tptr!=NULL;tptr=tptr->next)
         printf("%d ",tptr->data);
   }
     printf("\n");
}
void search(int val)
{
    NODE * tptr;
    for(tptr=head;tptr!=NULL;tptr=tptr->next)
    {
        if(tptr->data==val)
        {
          printf("The value is found\n");
          break;
        }
    }
    if(tptr==NULL)
        printf("The value is not found\n");
}
void delete_(int val)
{
  NODE* tptr,*prev;prev=NULL;
  for(tptr=head;tptr!=NULL;prev=tptr,tptr=tptr->next)
      if(tptr->data==val)
      break;
  if(tptr==head)
  {
    head=tptr->next;
    free(tptr);
  }
  else
  {
      prev->next=tptr->next;
      free(tptr);
  }

}

};
int main()
{
   linkedlist list1;
    int choice,val;
    while(1)
    {
        printf("-------------------------------\n");
        printf("1.Insert value at begining \n");
        printf("2.Insert value at end \n");
        printf("3.Insert value at sorted list\n");
        printf("4.Display\n");
        printf("5.Search the element\n");
        printf("6 To delete the element\n");
        printf("7.To reverse the list\n");
        printf("8.Exit\n");
        printf("-------------------------------\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                {
                    printf("Enter the value to insert:");
                    scanf("%d",&val);
                   list1.insertatbegin(val);
                    break;
                }
            case 2:
                {
                    printf("Enter the value to insert:");
                    scanf("%d",&val);
                    list1.insertatend(val);
                    break;
                }
            case 3:
                {
                    printf("Enter the value to insert:");
                    scanf("%d",&val);
                    list1.insertatsort(val);
                    break;
                }
            case 4:
                {
                    list1.display();
                    break;
                }
            case 5:
                {
                    printf("Enter the value for search:");
                    scanf("%d",&val);
                   list1. search(val);
                    break;
                }
            case 6:
                {
                    printf("Enter the value to delete:");
                    scanf("%d",&val);
                        list1.delete_(val);
                        list1.display();
                    break;
                }
            case 7:
                {
                   list1. reverse();
                    list1.display();
                    break;
                }
            case 8:
                exit(0);break;
            default: printf("Enter the valid choice:");
        }
    }
}
