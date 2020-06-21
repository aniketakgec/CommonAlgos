#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void insertAtBotttom(stack<int>&s1,int x)
{
    if(s1.empty()==true)
    {
        s1.push(x);
        return;
    }
    int y=s1.top();
    s1.pop();
    insertAtBotttom(s1,x);
    s1.push(y);
}
void reverseStackRecursion(stack<int>&s1)
{
    if(s1.empty()==true )
     return;
    int x=s1.top();
    s1.pop();
    reverseStackRecursion(s1);
    insertAtBotttom(s1,x);
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
 reverseStackRecursion(s);
 while(s.empty()==false)
 {
     cout<<s.top()<<endl;
     s.pop();
 }
    return 0;
    
}
