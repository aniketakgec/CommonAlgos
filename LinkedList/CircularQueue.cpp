/*
 Circular Queue Implementation
 */

#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Queue
{

T* arr;
int front;
int rear;
int max_size;
int curr_size;

public:
  Queue(int ds=10)
{
front=0;
max_size=ds;
rear=max_size-1;
curr_size=0;
arr=new T[ds];

}

bool isEmpty()
{
    return curr_size==0;
}


bool isFull()
{
    return curr_size==max_size;
}

void push(T data)  //enque function
{  if(!isFull())
    {
        rear=(rear+1)%max_size;
        arr[rear]=data;
        curr_size++;
    }
}

void pop()   // deque function
{
    if(!isEmpty())
    {
        front=(front+1)%max_size;
        curr_size--;
    }
}

T getFront()
{
    return arr[front];
}



};



int main()
{
Queue<int> q;
// number 1 to 10  inserted into queue
 for(int i=1;i<=10;i++)
 {
     q.push(i);
 }
 // deleting one element and inserting one element in queue
 q.pop();
 q.push(8);

 while(!q.isEmpty())
 {
     cout<<q.getFront()<<endl;
     q.pop();

 }


    return 0;
}