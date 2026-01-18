#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int *items;
	int curr_size;
	int total_size;
} pythonlist;

// This function simulates my_list = []
pythonlist* pythonlist_Create(){
	pythonlist *list = (pythonlist*)malloc(sizeof(pythonlist));
	list->total_size = 2;
	list->curr_size=0;
	list->items = (int*)malloc(list->total_size * sizeof(int));
}

void pythonlist_Append(pythonlist *list, int value){
	if (list->curr_size == list->total_size){
		printf("The list is full, current size is: %d. Resizing memory....\n", list->curr_size);
		
		list->total_size*=2;
		
		list->items = (int*)realloc(list->items, list->total_size * sizeof(int));
		
		printf("The memory has been expanded and the new capacity is: %d\n", list->total_size);
	}
	
	list->items[list->curr_size] = value;
	list->curr_size++;
}

void pythonlist_Print(pythonlist *list){
	printf("Python list's current state is: [");
	for (int i = 0; i < list->curr_size; i++){
		printf("%d", list->items[i]);
		if(i < list->curr_size - 1) printf(", ");
	}
	printf("]\n");
}

int main() {
	printf("--- Beginning the Simulation of the List Evolution---\n");
	
	pythonlist *mylist = pythonlist_Create();
	
	for (int i = 0; i < 6; i++){
		printf("Appending the value: %d\n", i );
		pythonlist_Append(mylist, i);
	}
	
	printf("\nFinal Result:\n");
	pythonlist_Print(mylist);
	
	free(mylist->items);
	free(mylist);
	
	return 0;
	
}