//Implementing stack using queue

#include<iostream>
#include<queue>
using namespace std;

struct Stack{
    queue<int> q1,q2;
};

Stack* push(int x)
{
    Stack *stack=new Stack;
    while (stack->q1.empty()==false)
    {
        stack->q2.push(stack->q1.front());
        stack->q1.pop();
    }
    stack->q1.push(x);
    while (stack->q2.empty()==false)
    {
       stack->q1.push(stack->q2.front());
       stack->q1.pop();
    }  
    return stack; 
}

void pop(Stack *stack)
{
    cout<<stack->q1.front();
    stack->q1.pop();
}

int main()
{
    Stack *stack=push(10);
    stack=push(20);
    stack=push(30);
    pop(stack);
}