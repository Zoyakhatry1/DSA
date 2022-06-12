//Move zeroes to the end of the array

#include<iostream>
using namespace std;

int* movezeroestoend(int arr[],int n)
{
   int count=0,j=0;
   for(int i=0;i<n;i++)
   {
     if(arr[i]!=0)
     {
       int a=arr[count];
       arr[count]=arr[i];
       arr[i]=a;
       count++;
     }
   }
      
   return arr;
}

int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n],*b;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    b=movezeroestoend(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
}