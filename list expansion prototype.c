#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int *items;
	int size;
	int capacity;
} Pylist;

Pylist* Pylist_Create(){
	Pylist *list = (Pylist*)malloc(sizeof(Pylist));
	list->capacity = 2;
	list->size=0;
	list->items = (int*)malloc(list->capacity * sizeof(int));
}

void Pylist_Append(Pylist *list, int value){
	if (list->size == list->capacity){
		printf("The list is full, current size is: %d. Resizing memory....\n", list->size);
		
		list->capacity*=2;
		
		list->items = (int*)realloc(list->items, list->capacity * sizeof(int));
		
		printf("The memory has been expanded and the new capacity is: %d\n", list->capacity);
	}
	
	list->items[list->size] = value;
	list->size++;
}

void Pylist_Print(Pylist *list){
	printf("Pylist's current state is: [");
	for (int i = 0; i < list->size; i++){
		printf("%d", list->items[i]);
		if(i < list->size - 1) printf(", ");
	}
	printf("]\n");
}

int main() {
	printf("--- Beginning the Simulation of the List Evolution---\n");
	
	Pylist *mylist = Pylist_Create();
	
	for (int i = 0; i < 6; i++){
		printf("Appending the value: %d\n", i * 10);
		Pylist_Append(mylist, i*10);
	}
	
	printf("\nFinal Result:\n");
	Pylist_Print(mylist);
	
	free(mylist->items);
	free(mylist);
	
	return 0;
	
}