#include<bits/stdc++.h>
using namespace std;
class Stack
{
private:
   vector<int> v;

public:

void push(int data)
{
    v.push_back(data);
}

bool empty()
{
    return v.size()==0;
}


int top()
{
    return v[v.size()-1];

}
void pop()
{
    if(!empty())
    {
        v.pop_back();
    }
}

};



int main()
{

 Stack s;
 int n;
 cin>>n;

 for(int i=0;i<n;i++)
 {
     s.push(i*i);
 }

 while(!s.empty())
 {
     cout<<s.top()<<endl;
     s.pop();

 }


    return 0;
}