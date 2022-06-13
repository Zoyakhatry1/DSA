//Using stl

#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_front(10);
    dq.push_front(20);
    dq.push_front(30);
    dq.push_back(40);
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    cout<<dq.size()<<endl;
    deque<int>::iterator it;
    for(it=dq.begin();it!=dq.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    dq.pop_back();
    dq.pop_front();
    for(it=dq.begin();it!=dq.end();it++)
    {
        cout<<*it<<" ";
    }
}