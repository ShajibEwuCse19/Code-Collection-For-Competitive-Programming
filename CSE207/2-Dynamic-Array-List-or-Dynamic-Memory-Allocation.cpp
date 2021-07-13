#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 2
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

int listMaxSize; //at any moment max number of elements the list can hold
int *list; // pointer to the list
int length; // idx of next insertion or number of elements in the list


void initialize_list()
{
	listMaxSize = LIST_INIT_SIZE;
	list = (int*)malloc(sizeof(int)*listMaxSize) ;
	length = 0 ;
}

int insert_item(int item)
{
	int * tempList ;
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
		int i;
        for( i = 0; i < length ; i++ ){
            tempList[i] = list[i] ; //copy all items from list to tempList. we can use: *(tempList + i) = *(list + i) , *(arrayName + index) and arrayName[index] both same. 
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	}

	list[length] = item ;
	length++ ;
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
}
