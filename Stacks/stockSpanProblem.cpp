#include<bits/stdc++.h>

using namespace std;
void printarr(int arr[],int n){
    stack<int> s;
    int a[n];
    for(int days=0;days<n;days++)
    {
        while( s.empty()==false and arr[s.top()]<arr[days])
        {
            s.pop();
        }
        int betterdays=s.empty()? 0: s.top();
        int span=days-betterdays;
        a[days]=span;
        s.push(days);
    }
     for(int days=0;days<n;days++)
        cout<<a[days]<<" ";
}
int main()
{
    int n=7;
    int arr[]={100,80,60,70,60,75,85};
    printarr(arr,n);


    return 0;
}