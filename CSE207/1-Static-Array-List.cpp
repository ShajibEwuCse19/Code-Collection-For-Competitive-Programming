#define LIST_MAX_SIZE 100
#define NULL_VALUE -999999
#define SUCCESS_VALUE 999999
#include <stdio.h>

int list[LIST_MAX_SIZE];
int length;


void initialize_list()
{
    length = 0 ;
}


int insert_item(int item)
{
    if (length == LIST_MAX_SIZE) return NULL_VALUE ;
    list[length] = item ;
    length++ ;
    return SUCCESS_VALUE ;
}

int get_item(int position)
{
    if( position < 0 || position >= length ) return NULL_VALUE;
    return list[position] ;
}

int search_item(int item)
{
    int i = 0;
    for (i = 0; i < length; i++)
    {
        if( list[i] == item ) return i;
    }
    return NULL_VALUE;
}


int delete_item_at(int position) //version 1, preserve order of items
{
    if ( position < 0 || position >= length ) return NULL_VALUE;
    int i;
    for (i = position + 1; i < length; i++)
    {
        list[i-1] = list[i] ; //move item left by one slot
    }
    length-- ;
    return SUCCESS_VALUE ;
}

/*
int delete_item_at(int position) //version 2, do not preserve order of items
{
    if (position < 0 || position >= length) return NULL_VALUE;
    list[position] = list[length-1] ;
    length-- ;
    return SUCCESS_VALUE ;
}
*/

int delete_item(int item)
{
    int position;
    position = search_item(item) ;
    if ( position == NULL_VALUE ) return NULL_VALUE;
    delete_item_at(position) ;
    return SUCCESS_VALUE ;
}

void print_array(){
    int i;
    for( i = 0; i < length; i++)
        printf("%d ", list[i]);
    printf("\n");
}

int main(){
    initialize_list();
    insert_item(10);
    insert_item(20);
    insert_item(30);
    insert_item(40);
    insert_item(50);
    insert_item(60);
    insert_item(70);
    insert_item(80);
    insert_item(90);
    insert_item(100);
    print_array();
    printf("\n");

    printf("Item at idx 3 = %d\n", get_item(3));
    printf("Item at idx -1 = %d\n", get_item(-1));
    printf("\n");

    printf("Find the idx of item 30 = %d\n", search_item(30));
    printf("Find the idx of item 150 = %d\n", search_item(150));
    printf("\n");

    print_array();
    delete_item_at(5);
    printf("After deleting the item at idx: 5\n");
    print_array();
    printf("\n");

    print_array();
    delete_item_at(-1);
    printf("After deleting the item at idx: -1\n");
    print_array();
    printf("\n");

    print_array();
    printf("After deleting item: 0\n");
    delete_item(0);
    print_array();
    printf("\n");

    print_array();
    printf("After deleting item: 30\n");
    delete_item(30);
    print_array();
    printf("\n");
}
