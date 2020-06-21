#include <bits/stdc++.h>

//LINKED LIST IMPLEMENTATION

using namespace std;

class node{
    public:
        int data;
        node* next;
        node(int d)
        {
            data=d;
            next=NULL;
        }
};


void insertAtHead(node*&head, int data)
{
    node* n=new node(data); // create a new node for insertion
    n->next=head;  //make the new node point to head
    head=n; //make new node as head
}

void printLinkedList(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"-->";
        
        head=head->next;
    }
}
int  length(node*head)  //function to calculate length of linked list
{
 
 int temp=0;
 while(head!=NULL)
   {
       head=head->next;
       temp++;
   }
   
   return temp;
    
}

void  insertAtTail(node*&head, int data){ // function to insert node at the end of linked list
    if(head==NULL)
    {  head=new node(data);
      return ;
        
        
    }
    
    node* tail=head;
     while(tail!=NULL)
   {
       tail=tail->next;
       
   }
   
   tail->next=new node(data);
   return ;
      
      
      
}

void insertAtMiddle(node* head,int data,int pos)// function which insert node at start,middle and end of linked list
{
    if(head==NULL or pos==0)
      insertAtHead(head,data);
    else if(pos>length(head))
      insertAtTail(head,data);
     else
     {                                  //fucntion to insert node anywhere in the moddle from the head positon in linked list
         int jump=1;
          node*temp=head;
         while(jump<=pos-1)
         {
             temp=temp->next;
             jump++;
         }
         
         
         node* n=new node(data);
         n->next=temp->next;
         temp->next=n; 
         }
}

int main() {
 node* head=NULL;
  insertAtHead(head,5);
   insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtMiddle(head,2,3);
    insertAtMiddle(head,1,4);
    
    printLinkedList(head);
    
  
  
 return 0;
}