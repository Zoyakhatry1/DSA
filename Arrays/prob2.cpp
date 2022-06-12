//Left rotate by x

#include<iostream>
using namespace std;

int* leftrotatebyone(int arr[],int n)
{
    int c=arr[0];
    for(int i=0;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1]=c;
    return arr;
}
int* leftrotate(int arr[],int n,int x)
{
    int *b;
    for(int i=1;i<=x;i++)
    {
      b=leftrotatebyone(arr,n);
    }
    return b;
}

int main()
{
    int n,x;
    cout<<"Enter size: ";
    cin>>n;
    cout<<"Enter the value of x: ";
    cin>>x;
    int arr[n],*b;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    b=leftrotate(arr,n,x);
    for(int i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
}