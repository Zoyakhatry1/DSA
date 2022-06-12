//Linked list implementation of stack

#include<iostream>
using namespace std;

struct Node{
    int x;
    Node *next;
    Node()
    {
        next=NULL;
    }
};

struct Stack
{
   Node *head;
   int size;
};

Stack* createStack()
{
    Stack *stack=new Stack;
    stack->size=0;
    stack->head=NULL;
    return stack;
}


void push(Stack *stack)
{
    int x;
    cout<<"Enter value: ";
    cin>>x;
    Node *temp=new Node;
    temp->x=x;
    temp->next=stack->head;
    stack->head=temp;
    stack->size++;
}

int isEmpty(Stack *stack)
{
   return(stack->head==NULL);
}

void pop(Stack *stack)
{
    if(isEmpty(stack))
    {
      cout<<"Empty"<<endl;
    }
    else{
       int res=stack->head->x;
       Node *temp=stack->head;
       stack->head=stack->head->next;
       delete(temp);
       stack->size--;
       cout<<res<<endl;
    }
}

void size(Stack *stack)
{
    cout<<stack->size<<endl;
}

void peek(Stack *stack)
{
    if(stack->head==NULL)
    {
        return;
    }
      cout<<stack->head->x<<endl;  
}

int main()
{
   Stack *stack=createStack();
   push(stack);
   push(stack);
   push(stack);
   push(stack);
   push(stack);
   pop(stack);
   pop(stack);
   size(stack);
   peek(stack);
}