//Implementing using linkedlist

#include<iostream>
using namespace std;

struct Node{
    int x;
    Node *next;
    Node(int d){
        next=NULL;
        x=d;
    }
};

struct Queue
{
    Node *front,*rear;
    Queue(){
        front=NULL;
        rear=NULL;
    }
};
    void enqueue(int x,Queue *queue)
    {
        Node *temp=new Node(x);
        if(queue->front==NULL)
        {
            queue->front=queue->rear=temp;
            return;
        }
        queue->rear->next=temp;
        queue->rear=temp;
    }
    void dequeue(Queue *queue){
        if(queue->front==NULL)
        {
            return;
        }
        Node *temp=queue->front;
        queue->front=queue->front->next;
        if(queue->front==NULL)
        {
            queue->rear=NULL;
        }
        cout<<temp->x<<endl;
        delete(temp);
    }

int main()
{
    Queue *queue=new Queue;
    enqueue(10,queue);
    enqueue(20,queue);
    enqueue(30,queue);
    enqueue(40,queue);
    dequeue(queue);
    dequeue(queue);
}