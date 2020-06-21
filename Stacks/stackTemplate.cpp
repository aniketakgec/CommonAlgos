#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Stack
{
private:
   vector<T> v;

public:

void push(T data)
{
    v.push_back(data);
}

bool empty()
{
    return v.size()==0;
}


T top()
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

 Stack<char> s; //here you can define any data type for which you want to contruct the stack
 int n,i;
 cin>>n;

 for(i=65;i<65+n;i++)
 {
     s.push(i);
 }

 while(!s.empty())
 {
     cout<<s.top()<<endl;
     s.pop();

 }


    return 0;
}