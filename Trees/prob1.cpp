//Basic Implementation

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

void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root!=NULL)
    {
       cout<<root->data<<" ";
       preorder(root->left);
       preorder(root->right);
    }
    
}

void postorder(Node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int height(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}

int main()
{
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<height(root)<<endl;
}
