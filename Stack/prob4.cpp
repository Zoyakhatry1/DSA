//Balanced Parenthesis

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool matching(char q,char s)
{
    return (q=='{'&&s=='}')||(q=='['&&s==']')||(q=='('&&s==')');
}

bool checkparenthesis(stack<char> q,string s)
{
   for(int i=0;i<s.length();i++)
   {
       if(s[i]=='{'||s[i]=='['||s[i]=='('){
           q.push(s[i]);
       }
       else{
           if(q.empty()){
               return false;
           }
           else if(matching(q.top(),s[i])==false){
               return false;
           }
           q.pop();
       }
   }
   return (q.empty()==true);
}

int main()
{
   stack<char> q;
   string s;
   bool res;
   cout<<"Enter the string: ";
   getline(cin,s);
   res=checkparenthesis(q,s);
   cout<<res<<endl;
}