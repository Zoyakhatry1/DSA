//Freq in an array
#include<iostream>
using namespace std;

void freq(int arr[],int n)
{
    int freq=1;
   for(int i=0;i<n;i++)
   {
       if(arr[i]==arr[i+1])
       {
          freq++;
       }
       else{
           cout<<arr[i]<<" "<<freq<<endl;
           freq=1;
       }
   }
}

int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    freq(arr,n);
}