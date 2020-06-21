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

int main() {
 node* head=NULL;
  insertAtHead(head,5);
   insertAtHead(head,4);
    insertAtHead(head,3);
    
    printLinkedList(head);
    
  
  
 return 0;
}