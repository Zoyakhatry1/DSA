//Evaluation of post expression

#include<iostream>
#include<string>
#include<stack>
#include<cmath>
using namespace std;

void prefix_eval(stack<int> s,string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        int a,b;
        if(str[i]=='*')
        {
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(b*a);
        }
        else if(str[i]=='/')
        {
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(b/a);
        }
        else if(str[i]=='+')
        {
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(b+a);
        }
        else if(str[i]=='-')
        {
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(b-a);
        }
        else if(str[i]=='^')
        {
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(pow(b,a));
        }
        else{
            //cout<<str[i]-'0'<<endl;
            if(str[i+1]=='0')
            {
               int p=str[i]-'0';
               s.push(p*10);
            }
            else if(str[i]=='0')
            {
                continue;
            }
            else{
              s.push(str[i]-'0');
            }   
        }
    }
    cout<<s.top()<<endl;
}

int main()
{
    stack<int> s;
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    //cout<<5*3<<endl;
    prefix_eval(s,str);
}