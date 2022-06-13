#include<iostream>
#include<cmath>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

void nodesatk(Node *root,int k)
{
    if(root==NULL){return;}
    if(k==0)
    {
        cout<<root->data<<" ";
    }
    else{
       nodesatk(root->left,k-1);
    nodesatk(root->right,k-1);
    } 
}

int main()
{
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    nodesatk(root,2);
}
