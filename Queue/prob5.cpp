//Reversing a queue

#include<iostream>
#include<iterator>
#include<queue>
#include<stack>

using namespace std;

void reverse(queue<int> &q)
{
    stack<int> s;
    while (q.empty()==false)
    {
        s.push(q.front());
        q.pop();
    }
    while (s.empty()==false)
    {
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    queue<int> q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    reverse(q1);
    while (q1.empty()==false)
    {
        cout<<q1.front()<<" ";
        q1.pop();
    }
    
}

