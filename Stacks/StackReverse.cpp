#include <bits/stdc++.h>
#define ll long long int

using namespace std;
void transfer(stack<int>&s1,stack<int>&s2,int n)
{
  for(int i=0;i<n;i++)
    {
        s2.push(s1.top());
        s1.pop();
    }
}
void reverseStack(stack<int>&s1)
{ int n=s1.size();
    stack<int>s2;
    for(int i=0;i<n;i++)
    {
          int x=s1.top();
          s1.pop();
        transfer(s1,s2,n-i-1);
        s1.push(x);
        transfer(s2,s1,n-i-1);

    }
  
}
int main() 
{ ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
 stack<int>s;
 s.push(1);
 s.push(2);
 s.push(3);
 s.push(4);
 reverseStack(s);
 while(s.empty()==false)
 {
     cout<<s.top()<<endl;
     s.pop();
 }
    return 0;
    
}
