//nth node from last

#include<iostream>
using namespace std;

struct Node{
    int num;
    Node *next;
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

void deletenthnode(Node *head)
{
    int n;
    cout<<"Enter the node: ";
    cin>>n;
    Node *first=head;
    if(head==NULL)
    {
        return;
    }
    int i;
    for(i=0;i<n;i++)
    {
        if(first==NULL) return;
       first=first->next;
    }
    Node *second=head;
    while (first!=NULL)
    {
        second=second->next;
        first=first->next;
    }
    cout<<second->num<<endl;
}

int main()
{
   struct Node *head=NULL;
   int choice;
   while (1)
   {
       cout<<"Enter choice: ";
       cin>>choice;
       switch (choice)
       {
       case 1:head=createNode(head);
           break;
        case 2:deletenthnode(head);
        break;
       default:
           exit (0);
       }
   }
   
}