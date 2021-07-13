Implementation - 1 (Static Stack)
====================================
#define QUEUE_MAX_SIZE 100

int data[QUEUE_MAX_SIZE] ;
int front; // index: where the next insertion will happen
int rear; // index: where the next deletion will happen
int length ; // number of items in the static arraylist

void initialize_queue()
{
    front = 0;
    rear = 0;
    length = 0;
}

int enqueue(int item)
{
    if(length == QUEUE_MAX_SIZE) return -1;
    data[front] = item;
    //front = front + 1;
    front = (front + 1) % QUEUE_MAX_SIZE; //circularly increment front
    length++;
    return 1;
}

int dequeue()
{
    if(length == 0)
        return -1;
    int item = data[rear];
    //rear = rear + 1;
    rear = (rear + 1) % QUEUE_MAX_SIZE; //circularly increment rear
    length--;
    return item; // return the item that is deleted
}

int main(){

}


  
  
Implementation - 2 (Static Stack using pointer)
================================================
same as stack implementation.


  
Implementation - 1 (Dynamic Stack using Doubly Linked List)
====================================================
#include<bits/stdc++.h>
using namespace std;
#define STACK_MAX 100
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

typedef struct node
{
    int item;
    struct node *next, *prev;
}Queue;

Queue *Front, *Rear; ///Head = Rear and Tail = Front is queue.

void initialization()
{
    Front = 0;///tail
    Rear = 0;///head
}

/// Function to insert an item from queue.
void enqueue(int item) ///using Doubly Linked list (insert last).
{
    Queue *new_node = (Queue*)malloc(sizeof(Queue)); ///item,next
    new_node->item = item;

    new_node->next = 0;
    new_node->prev = Front;
    Front = new_node;

    if(new_node->prev != 0)new_node->prev->next = new_node;

    else Rear = new_node;
}

bool isEmapty()
{
    return !Front and !Rear; ///return 1 (true) if Front = 0, otherwise it'll return 0(false).
}

/// Function to remove an item from queue.
int dequeue()
{
    if(isEmapty())return NULL_VALUE;
    int item = Rear->item;

    if(Rear == Front) ///tail == head
    {
        Rear = 0;
        Front = 0;
    }
    else
    {
        Queue *temp = Rear;

        Rear->next->prev = 0;
        Rear = Rear->next;

        free(temp);
    }

    return item;
}

/// Function to get front of queue
int Front_item()
{
    if(isEmapty())return NULL_VALUE;

    return Front->item;
}

/// Function to get rear of queue
int Rear_item()
{
    if(Rear == 0)return NULL_VALUE;

    return Rear->item;
}


int main()
{
    initialization();

    cout<<"Input  = 1 2 3 4 5"<<endl;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    //cout<<Rear_item()<<endl;
    //cout<<Front_item()<<endl;

    cout<<"Output = ";
    while(!isEmapty())
    {
        cout<<dequeue()<<" ";
    }
    cout<<endl;

}


Complexity: All above functions work wiht O(1) time.


