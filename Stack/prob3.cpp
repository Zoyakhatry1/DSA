//Stack in STL

#include<iostream>
#include<stack>
using namespace std;

int main()
{
   stack<int> stack;
   stack.push(10);
   stack.push(20);
   stack.push(30);
   stack.push(40);
   cout<<stack.size()<<endl;
   cout<<stack.top()<<endl;
   stack.pop();
   cout<<stack.top()<<endl;
   stack.pop();
   stack.pop();
   stack.pop();
   cout<<stack.empty();
}