//Implementing using array

#include<iostream>
using namespace std;

struct Dequeue
{
    int *arr;
    int front;
    int rear;
    int cap;
    int size;
};

Dequeue* createDequeue(int n)
{
   Dequeue *dequeue=new Dequeue;
   dequeue->front=0;
   dequeue->rear=0;
   dequeue->cap=n;
   dequeue->size=0;
   dequeue->arr=new int[n];
   return dequeue;
}
bool isFull(Dequeue *dequeue)
{
    return(dequeue->size==dequeue->cap);
}
bool isEmpty(Dequeue *dequeue)
{
    return(dequeue->size==0);
}
void insertatend(Dequeue *dequeue)
{
    int x;
    cout<<"Enter the value: ";
    cin>>x;
    if(isFull(dequeue)){
       return;
    }
    dequeue->rear=(dequeue->front+dequeue->size)%dequeue->cap;
    dequeue->arr[dequeue->rear]=x;
    dequeue->size++;
}

void insertatfront(Dequeue *dequeue)
{
   int x;
    cout<<"Enter the value: ";
    cin>>x;
    if(isFull(dequeue)){
       return;
    }
    dequeue->size++;
    dequeue->front=((dequeue->front)-1+(dequeue->cap))%dequeue->cap;
    dequeue->arr[dequeue->front]=x;
}

void deletefromfront(Dequeue *dequeue)
{
    if (isEmpty(dequeue))
    {
        return;
    }
    dequeue->front=(dequeue->front+1)%dequeue->cap; 
    dequeue->size--;  
}

void deletefromend(Dequeue *dequeue)
{
    if (isEmpty(dequeue))
    {
        return;
    }
    dequeue->rear=(dequeue->rear-1+dequeue->cap)%dequeue->cap; 
    dequeue->size--;  
}

void getFront(Dequeue *dequeue)
{
    if(isEmpty(dequeue)){
        return;
    }
    else{
        cout<<dequeue->arr[dequeue->front]<<endl;
    }
}

void getRear(Dequeue *dequeue)
{
    if(isEmpty(dequeue)){
        return;
    }
    else{
        cout<<dequeue->arr[dequeue->rear]<<endl;
    }
}

int main(){
   Dequeue *dequeue=createDequeue(4);
   insertatend(dequeue);
   insertatend(dequeue);
   insertatend(dequeue);
   insertatfront(dequeue);
   getFront(dequeue);
   getRear(dequeue);
   deletefromend(dequeue);
   deletefromfront(dequeue);
   getFront(dequeue);
   getRear(dequeue);
   insertatend(dequeue);
   insertatfront(dequeue);
   getFront(dequeue);
   getRear(dequeue);
}