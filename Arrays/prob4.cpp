//Leaders in an array

#include<iostream>
using namespace std;

void leader(int arr[],int n)
{
    for(int i=n-1;i>=0;i--)
    {
        int max;
        if(i==n-1)
        {
          max=arr[i];
          cout<<arr[i]<<" ";
        }
        else{
            if(max<arr[i])
            {
                max=arr[i];
                cout<<arr[i]<<" ";
            }
        }
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
    leader(arr,n);
}