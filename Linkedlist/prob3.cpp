//circular linkedlist(single)

#include<iostream>
using namespace std;

struct Node{
    int num;
    Node* next;
};

Node* createList(Node* head){
    Node* node=new Node;
    cout<<"Enter the value: ";
    cin>>node->num;
    if(head==NULL)
    {
        head=node;
        head->next=head;
    }
    else{
        Node* temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        node->next=head;
        temp->next=node;
    }
    return head;
}

void display(Node* head)
{
    if(head==NULL)
    {
        printf("Empty list");
        return;
    }
    Node* temp=head;
    while (temp->next!=head)
    {
        cout<<temp->num<<" ";
        temp=temp->next;
    }
    cout<<temp->num;
    cout<<endl;
}
Node* insertatbegin(Node* head)
{
    Node* node=new Node;
    cout<<"Enter the value: ";
    cin>>node->num;
    if(head==NULL)
    {
       head=node;
       head->next=head;
    }
    else
    {
      node->next=head->next;
      head->next=node;
      int swap=head->num;
      head->num=node->num;
      node->num=swap;
    }
    return head;   
}

Node* insertatend(Node* head)
{
    Node* node=new Node;
    cout<<"Enter value: ";
    cin>>node->num;
    if(head==NULL)
    {
        head=node;
        head->next=head;
    }
    else{
       node->next=head->next;
       head->next=node;
       int swap=head->num;
       head->num=node->num;
       node->num=swap;
       head=head->next;
    }
    return head;
}

Node* deletehead(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    else{
        Node* temp=head->next;
        head->num=head->next->num;
        head->next=head->next->next;
        free(temp);
        return head;
    }
}
Node* deletekthNode(Node* head)
{
   int k;
   cout<<"Enter k: ";
   cin>>k;
   if(head==NULL)
   {
       return NULL;
   }
   if(k==1)
   {
     Node *node=deletehead(head);
     return node;
   }
   Node *curr=head;
   for(int i=1;i<k-1;i++)
   {
       curr=curr->next;
   }
   Node *temp=curr->next;
   curr->next=temp->next;
   delete temp;
   return head;
}
Node* reverse(Node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        return head;
    }
    else{
        Node *prev=head;
        Node *temp=head;
        while (temp->next!=head)
        {
            temp=temp->next;
        }
        prev=temp;
        temp=head;
        Node *next=NULL;
        while(temp->next!=head)
        {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
           next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
            head=prev;
    }
    return head;
}
int main()
{
   Node* head=NULL;
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
       case 3:head=insertatbegin(head);
       break;
       case 4:head=insertatend(head);
       break;
       case 5:head=deletehead(head);
       break;
       case 6:head=deletekthNode(head);
       break;
       case 7:head=reverse(head);
       break;
       default:
          exit(0);
       }
   }
   
}