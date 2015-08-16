#include "LinkedList.h"
#include <stdio.h>
#include <malloc.h>


LinkedList *createLinkedList(){
	LinkedList *list = malloc(sizeof(LinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;

	return list;
}

void listAddLast(LinkedList *list,Element *element){

	if(list->head ==NULL)
		list->head = list->tail = element;
	
	else{
		list->tail->next = element;
		list->tail = element;
	}
  
	list->tail->next=NULL;
	
	if(element == NULL)
		list->length = 0;
	else
		list->length++;
}

Element *listRemoveLast(LinkedList *list){
  Element *tempElement;
  tempElement = list->tail;
  int i;
  
  if(list->head == NULL && list->tail == NULL)
    return NULL;
  
  else if(list->head==list->tail){		
    list->head = NULL;
    list->tail = NULL;
  }
  
  else{
    list->tail = list->head;
    
    for(i = 0 ; i < list->length - 2 ; i++)
      list->tail = list->tail->next;
    
      list->tail->next = NULL;
  }
  list->length--;
  
  return tempElement;
}

void listAddFirst(LinkedList *list,Element *element){

	if(list->head ==NULL){
		list->head = list->tail = element;
    list->tail->next = NULL;
  }
	
	else{
    element->next = list->head;
    list->head = element;
	}
	
	if(element == NULL)
		list->length = 0;
	else
		list->length++;
}

Element *listRemoveFirst(LinkedList *list){
  Element *tempElement;
  tempElement = list->head;
  int i;
  
  if(list->head == NULL && list->tail == NULL)
    return NULL;
  
  else if(list->head==list->tail){		
    list->head = NULL;
    list->tail = NULL;
  }
  
  else{
    list->head = list->head->next;
  }
  list->length--;
  
  return tempElement;
}
