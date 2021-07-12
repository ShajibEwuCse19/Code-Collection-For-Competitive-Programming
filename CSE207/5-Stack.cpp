Implementation - 1 (Static Stack)
====================================
#define STACK_MAX_SIZE 20

int data[STACK_MAX_SIZE]; // storage
int top; // index: where the next insertion will happen

void initialize_stack()
{
    top = 0 ; // initially there are no items
}

int push(int item)
{
    if(top == STACK_MAX_SIZE) return -1; // the static array is full
    data[top] = item ; // insert item at top
    top++; // update top so that next insertion can be a success
    return 1;
}

int pop()
{
    if(top == 0) return -1; // the static array is empty
    top--;
    return data[top]; // return the item that is deleted
}

int empty()
{
    if(top == 0)
        return 1;
    else
        return 0;
}


int full()
{
    if(top == STACK_MAX_SIZE)
        return 1;
    else
        return 0;
}

int main(){

}
  
  
Implementation - 2 (Static Stack using pointer)
================================================
#include<bits/stdc++.h>
using namespace std;
#define STACK_MAX 100
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

typedef struct
{
    int top;///next insertion
    int data[STACK_MAX]; ///array for store elements.
}Stack;


int push(Stack *s,int item)
{
    if( s->top >= STACK_MAX )return NULL_VALUE;

    s->data[s->top++] = item; ///first push in data[top]. then increment top = top + 1;

    return SUCCESS_VALUE;
}

int pop(Stack *s)
{
    if(s->top == 0)return NULL_VALUE;

    return s->data[--s->top]; ///first decrement top = top-1; then return data[top];coz top is the next insertion.
}


int main()
{
    Stack my_stack;
    my_stack.top = 0;

    push(&my_stack,1);
    push(&my_stack,2);
    push(&my_stack,3);

    while(my_stack.top != 0)
    {
        int item = pop(&my_stack);
        cout<<item<<" ";
    }

    cout<<endl;
}



  
Implementation - 1 (Dynamic Stack)
======================================
