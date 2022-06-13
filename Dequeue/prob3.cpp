//Max in all subarrays of size k
#include<iostream>
#include<deque>
using namespace std;

int main()
{
    //int arr[]={10,8,5,12,15,7,6};
    int arr[]={20,40,30,10,6};
    deque<int> dq;
    int k;
    int n=sizeof(arr)/sizeof(int);
    cout<<"Enter the value of k: ";
    cin>>k;
    for(int i=0;i<k;i++)
    {
      while (!dq.empty()&&arr[i]>=arr[dq.back()])
      {
        dq.pop_back();
      }
      dq.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        cout<<arr[dq.front()]<<" ";
        while (!dq.empty()&&dq.front()<=i-k)
        {
            dq.pop_front();
        }
        while (!dq.empty()&& arr[i]>=arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<" ";
}