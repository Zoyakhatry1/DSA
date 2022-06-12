//Implementation of queue

#include<iostream>
using namespace std;

struct Queue
{
    int *arr;
    int f;
    int r;
    int cap;
};

Queue* createQueue(int cap)
{
    Queue* queue=new Queue;
    queue->cap=cap;
    queue->f=-1;
    queue->r=-1;
    queue->arr=new int[cap];
    return queue;
}
bool isFull(Queue* queue)
{
    return(queue->r==queue->cap-1);
}
void enqueue(Queue *queue)
{
    if(isFull(queue)){
        return;
    }
    else{
        int x;
        cout<<"Enter x: ";
        cin>>x;
        if(queue->f==-1)
        {
            queue->f++;
        }
        queue->r++;
        queue->arr[queue->r]=x;
    }
}
bool isEmpty(Queue *queue)
{
    return(queue->f==-1&&queue->r==-1);
}

void dequeue(Queue *queue)
{
    if(isEmpty(queue))
    {
      return;
    }
    else{
        cout<<queue->arr[queue->f]<<" is popped"<<endl;
        queue->f++;
    }
}

void front(Queue *queue)
{
    if(isEmpty(queue))
    {
      return;
    }
    cout<<queue->arr[queue->f]<<endl;
}

void back(Queue *queue)
{
    if(isEmpty(queue))
    {
      return;
    }
    cout<<queue->arr[queue->r]<<endl;
}

void size(Queue *queue)
{
    if(isEmpty(queue))
    {
      cout<<"Empty"<<endl;
    }
    else{
        cout<<(queue->r-queue->f)+1<<endl;
    }
}

int main()
{
   Queue *queue=createQueue(5);
   enqueue(queue);
   enqueue(queue);
   enqueue(queue);
   enqueue(queue);
   size(queue);
   dequeue(queue);
   size(queue);
   front(queue);
   back(queue);
   dequeue(queue);
   size(queue);
}