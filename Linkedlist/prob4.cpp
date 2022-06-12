//circulardouble linkedlist

#include<iostream>
using namespace std;

struct Node{
    int num;
    Node* next;
    Node* prev;
};

Node* createList(Node *head)
{
    Node* node=new Node;
    cout<<"Enter the value: ";
    cin>>node->num;
    if(head==NULL)
    {
        head=node;
        head->next=head;
        head->prev=head;
    }
    else{
        Node *temp=head;
        while (temp->next!=head)
        {
            temp=temp->next;
        }
        node->next=head;
        node->prev=temp;
        head->prev=node;
        temp->next=node;
    }
    return head;
}

void display(Node *head)
{
  if (head==NULL)
  {
      return;
  }
  else{
      Node *temp=head;
      while(temp->next!=head)
      {
          cout<<temp->num<<" ";
          temp=temp->next;
      }
      cout<<temp->num;
      cout<<endl;
  }
  
}

Node* insertatbegin(Node* head){
   Node *node=new Node;
   cout<<"Enter the value: ";
   cin>>node->num;
   if(head==NULL)
   {
       head=node;
       head->next=head;
       head->prev=head;
   }
   else{
       head->next->prev=node;
       node->next=head->next;
       node->prev=head;
       head->next=node;
       int swap=head->num;
       head->num=node->num;
       node->num=swap;
   }
   return head;
}

Node* deletehead(Node *head)
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
        int swap=head->num;
        head->num=head->next->num;
        head->next->num=swap;
        head->next->next->prev=head;
        head->next=head->next->next;
        delete temp;
    }
    return head;
}

Node* deletelastnode(Node* head)
{
    if(head==NULL||head->next==head)
    {
        return NULL;
    }
    else{
        Node* temp=head->prev;
        temp->prev->next=head;
        head->prev=temp->prev;
        delete temp;
    }
    return head;
}

void reverse(Node* head)
{
    if(head==NULL)
    {
        cout<<"Empty"<<endl;
    }
    if(head->next==head)
    {
        cout<<head->num<<" "<<endl;
    }
    else{
        Node *temp=head->prev;
        cout<<"After reversing: "<<endl;
        while (temp!=head)
        {
            cout<<temp->num<<" ";
            temp=temp->prev;
        }
        cout<<temp->num<<" ";
        cout<<endl;
    }
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
        case 3: head=insertatbegin(head);
        break;
        case 4:head=deletehead(head);
        break;
        case 5: head=deletelastnode(head);
        break;
        case 6:reverse(head);
        break;
        default:
            exit(0);
        }
   }
   
}