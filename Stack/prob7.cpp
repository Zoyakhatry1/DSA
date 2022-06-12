//Infix to prefix

#include<iostream>
#include<string>
#include<stack>
using namespace std;

string strrev(string str)
{
    int len = str.length();
    int n = len-1;
    int i = 0;
    while(i<=n){
        swap(str[i],str[n]);
        n = n-1;
        i = i+1;
  }
  return str;
}

int checkpriority(char a){
    int x;
   if(a=='+'||a=='-')
   {
     x=1;
   }
   else if(a=='*'||a=='/')
   {
      x=2;
   }
   else if(a=='^')
   {
     x=3;
   }
   else if(a=='(')
   {
    x=0;
   }
   return x;
}

stack<char> infix_prefix(stack<char> s,string str){
    stack<char> res;
    
    for(int i=0;i<str.length();i++){
        if(str[i]=='*'||str[i]=='/'||str[i]=='+'||str[i]=='-'||str[i]=='^'){
            if(s.empty()==true){
                s.push(str[i]);
            }
            else{
                while(!s.empty()){
                    if(checkpriority(s.top())>checkpriority(str[i])){
                  res.push(s.top());
                     s.pop();
                  }
                  else{
                     s.push(str[i]);
                     break;
                  }
                }
                if(s.empty()){
                    s.push(str[i]);
                }
            }
        }
        else if(str[i]=='('){
            s.push(str[i]);
        }
        else if(str[i]==')'){
              while (s.top()!='(')
              {
                res.push(s.top());
                s.pop();
              }
              s.pop();
        }
        else{
            res.push(str[i]);
        }
    }
    while (!s.empty())
    {
        res.push(s.top());
        s.pop();
    }
    return res;
}

int main(){
    stack<char> s;
    stack<char> res;
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    str=strrev(str);
    res=infix_prefix(s,str);
    while (!res.empty())
    {
        cout<<res.top();
        res.pop();
    }
    
}
