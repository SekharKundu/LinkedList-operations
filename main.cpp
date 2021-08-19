#include<bits/stdc++.h>
using namespace std;

struct node{
int info;
struct node *link;
};
struct node *start=NULL;

void display()
{
    if(start==NULL)
    {
        cout<<"Empty list";
    }
    else
        {struct node *ptr=start;
        cout<<ptr->info<<"->";
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
            cout<<ptr->info<<"->";
        }
        }
}
void insertAtFirst(int info)
{
    struct node *neww=(struct node *)malloc(sizeof(struct node));
    neww->info=info;
    neww->link=NULL;

    if(start==NULL)
    {
        start=neww;
    }
    else
    {
        neww->link=start;
        start=neww;
    }
}
void insertAtLast(int info)
{
    struct node *neww=(struct node *)malloc(sizeof(struct node));
    neww->info=info;
    neww->link=NULL;

    if(start==NULL)
    {
        start=neww;
    }
    else
    {
        struct node *ptr=start;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=neww;
    }
}
void insertAtKey(int info, int key)
{
     struct node *neww=(struct node *)malloc(sizeof(struct node));
    neww->info=info;
    neww->link=NULL;

    if(start==NULL)
    {
        start=neww;
    }
    else
    {struct node *ptr=start;
    while(ptr->info!=key&&ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    if(ptr->info!=key)
    {
        cout<<"Key not found";
    }
    else
    {
        neww->link=ptr->link;
        ptr->link=neww;

    }
    }
}
void deleteFirst()
{
    if(start==NULL)
    {
        cout<<"Empty list";
    }
    else
    {
        struct node *temp=start;
        start=start->link;
        free(temp);
    }
}
void deleteLast()
{
    if(start==NULL)
    {
        cout<<"Empty list";
    }
    else
    {
        struct node *ptr1=start;
        struct node *ptr2=NULL;
        while(ptr1->link!=NULL)
        {
            ptr2=ptr1;
            ptr1=ptr1->link;
        }
        ptr2->link=NULL;
        free(ptr1);
    }
}
void deleteAtKey(int key)
{
    if(start==NULL)
    {
        cout<<"Empty list";
    }
    else
    {
        struct node *ptr=start;
        struct node *previous=NULL;
        while(ptr->info!=key&&ptr->link!=NULL)
        {   previous=ptr;
            ptr=ptr->link;
        }
        if(ptr->info!=key)
        {
            cout<<"Key not found";
        }
        else
        {
            previous->link=ptr->link;
            free(ptr);
        }
    }
}
void updateNode(int info,int key)
{
      if(start==NULL)
    {
        cout<<"Empty list";
    }
    else
    {
        struct node *ptr=start;
        while(ptr->info!=key && ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        if(ptr->info!=key)
        {
            cout<<"Key not found";
        }
        else
        {
            ptr->info=info;
        }
    }
}
int main()
{
   while(1)
{

    int ch,info,key;
    cout<<"\n1.Insert at first\n2.Insert at last\n3.Insert at key\n4.Delete at first\n5.Delete at last\n6.Delete at a key\n7.Update a node data\nEnter your choice: ";
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"Enter your info: ";
        cin>>info;
        system("CLS");
        insertAtFirst(info);
        display();
        break;
    case 2:
        cout<<"Enter your info: ";
        cin>>info;
        system("CLS");
        insertAtLast(info);
        display();
        break;
    case 3:
        cout<<"Enter your key: ";
        cin>>key;
        cout<<"Enter your info: ";
        cin>>info;
        system("CLS");
        insertAtKey(info,key);
        display();
        break;
    case 4:
        deleteFirst();
        display();
        break;
    case 5:
        deleteLast();
        display();
        break;
    case 6:
        cout<<"Enter your key: ";
        cin>>key;
        system("CLS");
        deleteAtKey(key);
        display();
        break;
    case 7:
        cout<<"Enter your key: ";
        cin>>key;
        cout<<"Enter your new info: ";
        cin>>info;
        system("CLS");
        updateNode(info,key);
        display();
        break;
    default:
        cout<<"Invalid choice!";
    }
}
}
