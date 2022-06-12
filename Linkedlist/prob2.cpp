//Doubly linked-list

#include<iostream>
using namespace std;

struct Node{
    int num;
    struct Node* next;
    struct Node* prev;
};

Node* createList(Node* head)
{
    Node* node=new Node;
    int x;
    cout<<"Enter x: ";
    cin>>x;
    node->num=x;
    node->next=NULL;
    if(head==NULL)
    {
        head=node;
        node->prev=NULL;
    }
    else{
        Node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        node->prev=temp;
        temp->next=node;  
    }
    return head;
}

void display(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->num<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* insertatBegin(Node* head)
{
    Node* node=new Node;
    int x;
    cout<<"Enter x: ";
    cin>>x;
    node->num=x;
    node->next=NULL;
    if(head==NULL)
    {
         head=node;
         node->prev=NULL;
    }
    else{
        Node *temp=head;
        node->next=temp;
        temp->prev=node;
        head=node;
    }
    return head;
}

Node* insertatend(Node* head)
{
    Node* node=new Node;
    cout<<"Enter x: ";
    cin>>node->num;
    if(head==NULL)
    {
        head=node;
    }
    else{
        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=node;
        node->prev=temp;
    }
    return head;
}

Node* reverse(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    else{
        Node* temp=head;
    Node* curr=NULL;
    while (temp!=NULL)
    {
        curr=temp->prev;
        temp->prev=temp->next;
        temp->next=curr;
        temp=temp->prev;
    }
    //cout<<curr->prev->num<<endl;
    return curr->prev;
    }
}

Node* deletehead(Node* head)
{
    if(head==NULL)
    {
        cout<<"Empty"<<endl;
    }
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    else{
        Node* temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
        return head;
    }
}

Node *delteLastnode(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    else{
        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
        delete(temp);
        return head;
    }
}
Node* insertatpos(Node* head)
{
    Node* node=new Node;
    int pos;
    cout<<"Enter x: ";
    cin>>node->num;
    cout<<"Enter pos: ";
    cin>>pos;
    node->next=NULL;
    if(head==NULL&&pos==1)
    {
        head=node;
        head->prev=NULL;
    }
    else{
        int i=0;
        Node* temp=head;
        while(temp!=NULL)
        {
            i++;
            temp=temp->next;
        }
        if(pos<=i)
        {
          Node* temp=head;
          int j=1;
          while (j<pos-1)
          {
              j++;
              temp=temp->next;
          }
          temp->next->prev=node;
          node->next=temp->next;
          node->prev=temp;
          temp->next=node;
        }
        else{
            cout<<"Position not available"<<endl;
        }
    }
    return head;
}
int main()
{
   Node* head=NULL;
   Node* rev=NULL;
   int choice;
   while (1)
   {
       cout<<"Enter choice: ";
       cin>>choice;
       switch (choice)
       {
       case 1:head=createList(head);
           break;
       case 2:display(head);
       break;
       case 3:head=insertatBegin(head);
       break;
       case 4:head=insertatend(head);
       break;
       case 5:head=reverse(head);
       break;
       case 6:head=deletehead(head);
       break;
       case 7:head=delteLastnode(head);
       break;
       case 8:head=insertatpos(head);
       break;
       default:
           exit(0);
       }
   }
   
}