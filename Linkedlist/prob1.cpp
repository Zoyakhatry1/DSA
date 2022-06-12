#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
   int num;
   struct Node* next;
};

Node* createNode(Node* head)
{
    Node* node = new Node;
    int x;
    cout<<"ENter x: ";
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

// int searching(Node *head,int x)
// {
//     int i=1;
//     Node* temp= head;
//     while(temp!=NULL)
//     {
//         if(temp->num==x)
//         {
//             return i;
//         }
//         else{
//             i++;
//             temp=temp->next;
//         }
//     }
//     return -1;
// }

int searching(Node* head,int x)
{
    if(head==NULL)
    {
        return -1;
    }
    if(head->num==x)
    {
        return 1;
    }
    else{
        int res=searching(head->next,x);
        if(res==-1)
        {
            return -1;
        }
        else{
            return (res+1);
        }
    }
    
}



int main()
{
   Node *head=NULL;
   int choice;
   while(1)
   {
     cout<<"Enter choice: ";
     cin>>choice;
     switch (choice)
     {
     case 1:head=createNode(head);
         break;
     case 3:int x,res;
     cin>>x;
     res=searching(head,x);
     cout<<res;
     default:
         exit(0);
     }
   }
}