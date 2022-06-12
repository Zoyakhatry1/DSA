//left rotate by reversing

#include<iostream>
using namespace std;

void reverse(int arr[],int low,int high)
{
    while (low<high)
    {
        int a= arr[low];
        arr[low]=arr[high];
        arr[high]=a;
        low++;
        high--;
    }
    
}

void leftrotate(int arr[],int n,int d)
{
    reverse(arr,0,n-1);
    reverse(arr,0,n-d-1);
    reverse(arr,d-1,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n,d;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter value of d: ";
    cin>>d;
    leftrotate(arr,n,d);
}