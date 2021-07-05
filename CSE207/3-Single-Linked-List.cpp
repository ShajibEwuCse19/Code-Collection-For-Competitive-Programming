#include<bits/stdc++.h>
using namespace std;
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct node
{
    int item;
    struct node* next; /// points to the next node
};

struct node *head; /// points to the first node of the linked list

void initialize_list()
{
    head = 0;  ///initially set to NULL
}

int insert_item(int item) ///insert at the beginning
{
    ///step-1: create a new node
	struct node* new_node ; ///stores the address of the new node
	new_node = (struct node*) malloc (sizeof(struct node)) ;
	new_node->item = item;
	new_node->next = 0;

    ///step-2: update the pointers of the new node
	new_node->next = head ; ///point to previous first node

	///step-3: update the head of the linked list
	head = new_node ;
	return SUCCESS_VALUE ;
}


int delete_item(int item)
{
	struct node* temp, *prev ;
	temp = head ; ///start at the beginning
	while (temp != 0)
	{
		if (temp->item == item) break ;
		prev = temp;
		temp = temp->next ; ///move to next node
	}
	if (temp == 0) return NULL_VALUE ; ///item not found to delete
	if (temp == head) ///delete the first node
	{
		head = head->next ;
		free(temp) ;
	}
	else
	{
		prev->next = temp->next ; ///delete node except first one.
		free(temp);
	}
	return SUCCESS_VALUE ;
}


struct node* search_item(int item)
{
	struct node * temp ;
	//start from the beginning
	temp = head ;
	while (temp != 0)
	{
		if (temp->item == item) return temp ;
		temp = temp->next ; //move to next node
	}
	return 0 ;
}

void print_list()
{
    struct node *temp;
    temp = head;///start from the head

    while(temp != 0)
    {
        cout<<temp->item<<" ";
        temp = temp->next; ///move to the next
    }
    cout<<endl;
}

int main(){
    initialize_list();
    insert_item(10);///last item.
    insert_item(20);
    insert_item(30);
    insert_item(40);
    insert_item(50);
    insert_item(60); ///first item
    ///list = head->60->50->....20->10

    cout<<"Current List = ";
    print_list();

    cout<<"List after delete last element 10 = ";
    delete_item(10);///last item
    print_list();

    cout<<"List after delete first element 60 = ";
    delete_item(60);///first item
    print_list();

    cout<<"List after delete mid element 30 = ";
    delete_item(30);///any mid element
    print_list();

    cout<<"Try to delete element 99 which is not contain in the list = ";
    delete_item(99); ///item not found
    print_list(); cout<<"The list is unchanged "<<endl<<endl<<endl;


    cout<<"Search item 20"<<endl;
    struct node *n = search_item(20);
    cout<<"Return Value = "<<n->item<<endl;
    if(n->item == 20)cout<<"20 found in the list"<<endl;

}
