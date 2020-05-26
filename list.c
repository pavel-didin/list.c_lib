#include "list.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define NOT_FOUND -1

List *list_append(List *head, int item, LIST_ERR *err)
{
    //create list item
    List *new_item = (List *) malloc(sizeof(List));
    if (new_item == NULL) {
		fprintf(stderr, "Not enough memory\n");
		if (err != NULL)
			*err = EMALLOC;
		return head;
	}
    new_item->item = item;
    new_item->next = NULL;
    new_item->previous = NULL;
    if (head)
    {
        List *list;
	if (list == NULL) {
		fprintf(stderr, "Not enough memory\n");
		if (err != NULL)
			*err = EMALLOC;
		return head;
	}
        //go to the end
        for (list = head; list->next; list = list->next);
        list->next = new_item; //append
        new_item->previous = list;
    }
    else
    {
        head = new_item; //init (create) list
    }
    *err = ESUCCESS;
    return head;
}

List *list_add(List *head, int item, LIST_ERR *err)
{
    //create list item
    List *new_item = (List *) malloc(sizeof(List));
    if (new_item == NULL) {
		fprintf(stderr, "Not enough memory\n");
		if (err != NULL)
			*err = EMALLOC;
		return head;
	}
    new_item->item = item;
    new_item->previous = NULL;
    new_item->next = head;
    if (head)
        head->previous = new_item;
    *err = ESUCCESS;
    return new_item;
}

void list_destroy(List *list, LIST_ERR *err)
{
    if (list == NULL) {
	fprintf(stderr, "Invalig size: list\n");
	if (err != NULL)
		*err = ESIZE;
	return;
    }
    while (list)
    {
        List *list1 = list;
	if (list1 == NULL) {
		fprintf(stderr, "Not enough memory\n");
		if (err != NULL)
			*err = EMALLOC;
		return;
	}
        list = list->next;
        free(list1);
    }
    *err = ESUCCESS;
}

void list_reverse_print(List *head, LIST_ERR *err)
{
    List *list = head;
    if (head == NULL) {
		fprintf(stderr, "Invalid size: list\n");
    if (err != NULL)
        *err = ESIZE;
    return;
	}
    if (list == NULL) {
		fprintf(stderr, "Not enough memory\n");
    if (err != NULL)
        *err = EMALLOC;
    return;
	}
    for ( ; list->next; list = list->next);
    for ( ; list; list = list->previous)
        printf("%d ", list->item);
    printf("\n");
    *err = ESUCCESS;
}

void list_print(List *head, LIST_ERR *err)
{
    List *list = head;
    if (list == NULL) {
		fprintf(stderr, "Not enough memory\n");
		if (err != NULL)
			*err = EMALLOC;
		return;
	}
    for ( ; list; list = list->next)
        printf("%d ", list->item);
    printf("\n");
    *err = ESUCCESS;
}


List *list_delete(List *head, unsigned index, LIST_ERR *err)
{
    List *list = head;
    unsigned i;
    if (head == NULL) {
		fprintf(stderr, "Invalig size: list\n");
		if (err != NULL)
			*err = ESIZE;
		return head;
	}
    if (list == NULL) {
		fprintf(stderr, "Not enough memory\n");
		if (err != NULL)
			*err = EMALLOC;
		return head;
	}
    for (i = 0; i < index; i++)
    {
        if (!list->next) {
		    fprintf(stderr, "Invalig size: list\n");
		    if (err != NULL)
			    *err = ESIZE;
		    return head;
	    }
        list = list->next;
    }
    if (list->previous)
        list->previous->next = list->next;
    else
        head = head->next;
    if (list->next)
        list->next->previous = list->previous;
    free(list);
    *err = ESUCCESS;
    return head;
}

List *list_delete_first(List *head, LIST_ERR *err)
{
    List *list = head;
    if (head == NULL) {
		fprintf(stderr, "Invalig size: list\n");
		if (err != NULL)
			*err = ESIZE;
		return head;
	}
    if (list == NULL) {
		fprintf(stderr, "Not enough memory\n");
		if (err != NULL)
			*err = EMALLOC;
		return head;
	}
    head = head->next;
    if (head)
        head->previous = NULL;
    free(list);
    *err = ESUCCESS;
    return head;
}

List *list_delete_last(List *head, LIST_ERR *err)
{
    List *list = head;
    if (head == NULL) {
		fprintf(stderr, "Invalig size: list\n");
		if (err != NULL)
			*err = ESIZE;
		return head;
	}
    if (list == NULL) {
		fprintf(stderr, "Not enough memory\n");
		if (err != NULL)
			*err = EMALLOC;
		return head;
	}
    if (!head->next)
    {
        free(head);
        return NULL;
    }
    for ( ; list->next; list = list->next);
    if (list->previous)
        list->previous->next = NULL;
    free(list);
    *err = ESUCCESS;
    return head;
}

List *list_insert(List *head, unsigned index, int item, LIST_ERR *err)
{
    List *list = head, *new_item;
    unsigned i;
    if (!head && index) {
		fprintf(stderr, "Invalig size: list\n");
		if (err != NULL)
			*err = ESIZE;
		return head;
	}
    if (!head || !index)
        return list_add(head, item, err);
    for (i = 0; i < index-1; i++)
    {
        list = list->next;
        if (!list){
		    fprintf(stderr, "Invalig size: list\n");
		    if (err != NULL)
			    *err = ESIZE;
		    return head;
	    }
    }
    new_item = (List *) malloc(sizeof(List));
    if (list == NULL) {
		fprintf(stderr, "Not enough memory\n");
		if (err != NULL)
			*err = EMALLOC;
		return head;
	}
    new_item->item = item;
    new_item->next = list->next;
    new_item->previous = list;
    if (list->next)
        list->next->previous = new_item;
    list->next = new_item;
    *err = ESUCCESS;
    return head;
}

int list_get(List *list, unsigned index, LIST_ERR *err)
{
    unsigned i;
    for (i = 0; list; list = list->next, i++)
        if (i == index) {
            *err = ESUCCESS;
            return list->item;
        }
		fprintf(stderr, "Invalig size: list\n");
		if (err != NULL)
			*err = ESIZE;
		return NOT_FOUND;
}

void list_set(List *list, unsigned index, int item, LIST_ERR *err)
{
    unsigned i;
    for (i = 0; list; list = list->next, i++)
        if (i == index)
        {
            list->item = item;
            *err = ESUCCESS;
            return;
        }
    fprintf(stderr, "Invalig size: list\n");
	if (err != NULL)
		*err = ESIZE;
}

int list_find(List *list, int item, LIST_ERR *err)
{
    unsigned i;
    for (i = 0; list; list = list->next, i++)
        if (list->item == item) {
            *err = ESUCCESS;
            return i;
        }
    fprintf(stderr, "Not found: list\n");
	if (err != NULL)
		*err = EFOUND;
    return NOT_FOUND;
}

unsigned list_size(List *list, LIST_ERR *err)
{
    unsigned i;
    for(i = 0; list; list = list->next, i++);
    *err = ESUCCESS;
    return i;
}
