//Infix to postfix

#include<iostream>
#include<string>
#include<stack>
using namespace std;

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

void infix_postfix(stack<char> s,string str){
    
    for(int i=0;i<str.length();i++){
        if(str[i]=='*'||str[i]=='/'||str[i]=='+'||str[i]=='-'||str[i]=='^'){
            if(s.empty()==true){
                s.push(str[i]);
            }
            else{
                while(!s.empty()){
                    if(checkpriority(s.top())>=checkpriority(str[i])){
                  cout<<s.top();
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
                cout<<s.top();
                s.pop();
              }
              s.pop();
        }
        else{
            cout<<str[i];
        }
    }
    while (!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    
}

int main(){
    stack<char> s;
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    infix_postfix(s,str);
}
