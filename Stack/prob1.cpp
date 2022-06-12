//array implementation of stack

#include<iostream>
using namespace std;

struct Stack
{
   int top;
   int cap;
   int *arr;
};

Stack* createStack(int cap)
{
    Stack *stack=new Stack;
    stack->cap=cap;
    stack->top=-1;
    stack->arr=new int[cap];
    return stack;
}

int isFull(Stack *stack)
{
    return(stack->top==stack->cap-1);
}

int isEmpty(Stack *stack)
{
    return(stack->top==-1);
}

void push(Stack *stack)
{
    if (isFull(stack))
    {
        cout<<"Stack is Full"<<endl;
    }
    else{
        int num;
        cout<<"Enter number: ";
        cin>>num;
        stack->top++;
        stack->arr[stack->top]=num;
    }
}

void pop(Stack *stack)
{
    if(isEmpty(stack))
    {
       cout<<"Stack is Empty"<<endl;
    }
    else{
        cout<<stack->arr[stack->top]<<" is popped from stack"<<endl;
        stack->top--;
    }
}

void size(Stack *stack)
{
    cout<<"Size is "<<stack->top+1<<endl;
}

void peek(Stack *stack)
{
    cout<<stack->arr[stack->top]<<" is the peek element"<<endl;
}

int main()
{
   int cap;
   cout<<"Enter capacity: ";
   cin>>cap;
   Stack *stack=createStack(cap);
   push(stack);
   push(stack);
   push(stack);
   push(stack);
   push(stack);
   push(stack);
   pop(stack);
   peek(stack);
   size(stack);
}