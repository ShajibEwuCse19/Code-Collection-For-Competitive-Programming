#include<bits/stdc++.h>
using namespace std;
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
struct node
{
    int item ; //stores value
    struct node *next ; //will keep memory address of next node
    struct node *prev ; //will keep memory address of previous node
};

struct node * head ;
struct node * tail ;

void initialize_list()
{
    head = 0 ; //set to NULL
    tail = 0 ; //set to NULL
}

int insert_first(int item)
{
    ///step-1: create a new node
    struct node *new_node = (struct node*) malloc (sizeof(struct node)) ;
    new_node->item = item ;///update item.

    ///step-2: update the prev and next pointers of the new node
    new_node->prev = 0 ; ///no previous node as this is the first item
    new_node->next = head ;///point head as it's first node.

    /// step-3: update linked head pointer variables: head and tail
    head = new_node ;

    /// step-4: update the pointer variables of the nodes that
    ///might be affected due to the insertion
    if ( new_node->next != 0 ) ///if there is multiple element in the list
        new_node->next->prev = new_node ; ///update prev node of the next node.
    else
        tail = new_node ; ///this is the first node in the head (only one element in the list).

    return SUCCESS_VALUE ;
}

int insert_last(int item)
{
    ///step-1: create a new node
    struct node *new_node = (struct node*) malloc (sizeof(struct node)) ;
    new_node->item = item ;///update item.

    ///step-2: update the prev and next pointers of the new node
    new_node->next = 0 ; ///no next node as this is the last node
    new_node->prev = tail ;///point tail as it's last node.

    /// step-3: update linked head pointer variables: head and tail
    tail = new_node ;

    /// step-4: update the pointer variables of the nodes that
    ///might be affected due to the insertion
    if ( new_node->prev != 0 ) ///multiple element in the list already inserted.
        new_node->prev->next = new_node ; ///update next node of the last node.
    else
        head = new_node ; ///this is the first node in the head

    return SUCCESS_VALUE ;
}

int delete_item(int item)
{
    struct node *temp,*prev;
    temp = head; ///we can use temp = tail to traverse tail to head.

    ///keep tacking prev and item node.
    while(temp != NULL) ///searching the item in the list.
    {
        if(temp->item == item)break;
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)return NULL_VALUE; ///item not found.
    else if(temp == head) ///if the item is head or only element.
    {
        head = temp->next; ///head will be next node of temp. So, update head.
        temp->next->prev = 0; ///also update prev of the next node of temp(current head). coz temp will be romoved.
        free(temp);
    }
    else if (temp == tail) ///if the item is tail node.
    {
        tail = temp->prev; ///tail will be prev node of the current node(temp). So, update tail.
        temp->prev->next = 0; ///also update next node of the prev node of temp (current tail). coz temp will be removed.
        free(temp);
    }
    else ///if the item is any node except head or tail.
    {
        prev->next = temp->next; ///update next node of prev node.coz, temp will be removed.
        temp->next->prev = prev;///update prev node of the next node of temp. coz, temp will be removed.
        free(temp);
    }


}

///delete item from tail
int delete_item(int item)
{
    struct node *temp,*next,*prev;
    temp = tail;

    while(temp != NULL)
    {
        if(temp->item == item)
        {
            if(temp == tail)
            {
                tail = temp->prev; ///tail will be previous node. So, update tail.
                temp->prev->next = 0; /// So, next of prev node will be 0.
                free(temp);
            }
            else if(temp == head)
            {
                head = temp->next; ///head will be next of temp.
                temp->next->prev = 0; ///prev of temp->next will be 0
                free(temp);
            }
            else
            {
                ///remove the item which is not in head or tail
                ///A-><-B-><-C then, A-><-temp-><-C then, A-><-C. Here, A = temp->prev and C = temp->next and A = temp.
                temp->next->prev = temp->prev; 
                temp->prev->next = temp->next;
                free(temp);
            }

            return SUCCESS_VALUE;
        }

        temp = temp->prev;
    }
    return NULL_VALUE;

}

///Print Functions.

void print_list_from_head_to_tail()
{
    struct node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->item<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void print_list_from_tail_to_head()
{
    struct node *temp = tail;
    while(temp != NULL)
    {
        cout<<temp->item<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}

int main(){
    initialize_list();

    insert_first(30);
    insert_first(20);
    insert_first(10);

    cout<<"List = ";
    print_list_from_head_to_tail(); ///head -> 10 <-> 20 <-> 30 <-> tail

    insert_last(40);
    insert_last(50);

    cout<<"List from head to tail = ";
    print_list_from_head_to_tail();///head -> 10 <-> 20 <-> 30 <-> 40 <-> 50 <- tail

    cout<<"List from tail to head = ";
    print_list_from_tail_to_head();

    cout<<endl<<endl<<endl;

    cout<<"Performing delete operation in different position in the list "<<endl<<endl;
    delete_item(head->item);///delete_item(10);
    cout<<"List after delete fist element = "; ///20 30 40 50
    print_list_from_head_to_tail();

    delete_item(50);///delete_item(tail->item);
    cout<<"List after delete last element = "; ///20 30 40
    print_list_from_head_to_tail();

    delete_item(30);
    cout<<"List after delete mid element = "; ///20 40
    print_list_from_head_to_tail();

}
