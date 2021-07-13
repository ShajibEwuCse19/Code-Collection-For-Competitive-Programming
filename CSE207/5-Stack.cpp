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



  
Implementation - 1 (Dynamic Stack using Linked List)
====================================================
#include<bits/stdc++.h>
using namespace std;
#define STACK_MAX 100
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

//typedef struct node Stack;

typedef struct node
{
    int item; ///data
    struct node *next; ///next pointer
}Stack; ///change type name

Stack *root; ///struck node *root

void initialize_root()
{
    root = 0; ///initially root is zero coz no element in stack.
}

bool isEmapty()
{
    return !root; ///return 1 (true) if root = 0, otherwise it'll return 0(false).
}

void push(int item) ///insert item one after another.
{
    Stack *new_node = (Stack*)malloc(sizeof(Stack)); ///create new node

    new_node->item = item; ///insert item
    new_node->next = root; ///next will be root
    
    root = new_node; ///root will be new_node
}

int pop()///remove item from Last to First
{
    if(isEmapty()) return NULL_VALUE; ///check stack empty or not.

    Stack *temp = root; ///temporary variable which point in root.
    root = root->next; ///root will be popped.So, update root to next item.

    int popped = temp->item; /// temp item will be popped which was root.
    free(temp); ///free memory 

    return popped; ///return the temp->item.
}

int peek() ///item from root.
{
    if(isEmapty())return NULL_VALUE;///check stack empty or not.

    return root->item;
}

int main()
{
    initialize_root();

    cout<<"Input  = 1 2 3"<<endl;;
    push(1);
    push(2);
    push(3);

    //cout<<"Peek value = "<<peek()<<endl;
    //cout<<"The stack is Empty or not = "<<isEmapty()<<endl;

    cout<<"Output = "; ///3 2 1
    while(!isEmapty())
    {
        cout<<pop()<<" ";
    }
    cout<<endl;

    //cout<<"The stack is Empty or not = "<<isEmapty()<<endl;
}

Complexity: push(), pop(), isEmpty() and peek() all take O(1) time



