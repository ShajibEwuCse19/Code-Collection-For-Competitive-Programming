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


  
Implementation - 1 (Dynamic Stack using Linked List)
====================================================



Complexity: 


