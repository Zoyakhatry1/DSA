//Max value of arr[j]-arr[i] where j>i

#include<iostream>
using namespace std;

// int maxdiff(int arr[],int n)
// {
//     int res=arr[1]-arr[0],res2;
//    for(int i=1;i<n;i++)
//    {
//        for(int j=0;j<i;j++)
//        {
//           res2=arr[i]-arr[j];
//           if(res2>res)
//           {
//               res=res2;
//           }
//        }
//    }
//    return res;
// }

int maxdiff(int arr[],int n)
{
   int res=arr[1]-arr[0];
   int minval=arr[0];
   for(int j=1;j<n;j++)
   {
       res=max(res,arr[j]-minval);
       minval=min(arr[j],minval);
   }
   return res;
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
    d=maxdiff(arr,n);
    cout<<d;
}