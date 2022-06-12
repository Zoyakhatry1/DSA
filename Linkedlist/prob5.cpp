//sorted insert in sigular linked list

#include<iostream>
using namespace std;

struct Node{
   int num;
   struct Node* next;
};

Node* createNode(Node* head)
{
    Node* node = new Node;
    int x;
    cout<<"Enter x: ";
    cin>>x;
    node->num=x;
    node->next=NULL;
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
    }
    return head;
}

Node* sortedInsert(Node* head)
{
   Node* node=new Node;
   cout<<"Enter the number: ";
   cin>>node->num;
   Node* temp=head;
   if(node->num<temp->num)
   {
       node->next=temp;
       head=node;
   }
   while (temp->next!=NULL)
   {
       if(node->num>temp->num&&node->num<temp->next->num)
       {
           node->next=temp->next;
           temp->next=node;
       }
       else{
           temp=temp->next;
       }
   }
   if (temp->num<node->num)
   {
       temp->next=node;
       node->next=NULL;
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
        case 1:head=createNode(head);
            break;
        case 2:head=sortedInsert(head);
        break;
        case 3:display(head);
        break;
        default:
          exit(0);
        }
    }
}