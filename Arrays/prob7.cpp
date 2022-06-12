//Stock Buy and sell

#include<iostream>
using namespace std;

int stockbuyandsell(int arr[],int n)
{
    int sum=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            sum=sum+(arr[i-1]-arr[i]);
        }
    }
    return sum;
}

int main()
{
    int n,res;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   res= stockbuyandsell(arr,n);
   cout<<res;
}