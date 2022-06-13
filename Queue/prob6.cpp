//Generate numbers with given digits

#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main()
{
  queue<string> q;
  int d;
  cout<<"Enter the no.of digits: ";
  cin>>d;
  string s[d];
  for(int i=0;i<d;i++)
  {
    string no;
    cout<<"Enter digit: ";
    cin>>no;
    s[i]=no;
    q.push(no); 
 }
//   q.push("5");
//   q.push("6");
  int n;
  cout<<"Enter n: ";
  cin>>n;
  for(int i=0;i<n;i++)
  {
    string c=q.front();
    q.pop();
    cout<<c<<" ";
    for (int i = 0; i < d; i++)
    {
        q.push(c+s[i]);
    }    
  }
}
