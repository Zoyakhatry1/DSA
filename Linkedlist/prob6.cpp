//Middle of a singly linkedlist

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

// void middle(Node* head)
// {
//     Node* temp=head;
//     int i=0;
//     while (temp!=NULL)
//     {
//         i++;
//         temp=temp->next;
//     }
//     temp=head;
//     int j=0;
//     while (j!=(i/2))
//     {
//        j++;
//        temp=temp->next;
//     }
//     cout<<temp->num<<endl;   
// }

void middle(Node* head)
{
    Node *slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->num<<endl;
}

int main()
{
    int choice;
    Node* head=NULL;
    while (1)
    {
        cout<<"Enter choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:head=createNode(head);
            break;
        case 2:middle(head);
        break;
        default:
           exit(0);
        }
    }
    
}