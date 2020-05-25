#include "list.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

List *list_append(List *head, int item)
{
    //create list item
    List *new_item = (List *) malloc(sizeof(List));
    new_item->item = item;
    new_item->next = NULL;
    new_item->previous = NULL;
    if (head)
    {
        List *list;
        //go to the end
        for (list = head; list->next; list = list->next);
        list->next = new_item; //append
        new_item->previous = list;
    }
    else
    {
        head = new_item; //init (create) list
    }
    return head;
}

List *list_add(List *head, int item)
{
    //create list item
    List *new_item = (List *) malloc(sizeof(List));
    new_item->item = item;
    new_item->previous = NULL;
    new_item->next = head;
    if (head)
        head->previous = new_item;
    return new_item;
}

void list_destroy(List *list)
{
    while (list)
    {
        List *list1 = list;
        list = list->next;
        free(list1);
    }
}

void list_reverse_print(List *head)
{
    List *list = head;
    if (list)
        for ( ; list->next; list = list->next);
    for ( ; list; list = list->previous)
        printf("%d ", list->item);
    printf("\n");
}

void list_print(List *head)
{
    List *list = head;
    for ( ; list; list = list->next)
        printf("%d ", list->item);
    printf("\n");
}


List *list_delete(List *head, unsigned index)
{
    List *list = head;
    unsigned i;
    if (!head)
        return head;
    for (i = 0; i < index; i++)
    {
        if (!list->next)
            return head;
        list = list->next;
    }
    if (list->previous)
        list->previous->next = list->next;
    else
        head = head->next;
    if (list->next)
        list->next->previous = list->previous;
    free(list);
    return head;
}

List *list_delete_first(List *head)
{
    List *list = head;
    if (!head)
        return head;
    head = head->next;
    if (head)
        head->previous = NULL;
    free(list);
    return head;
}

List *list_delete_last(List *head)
{
    List *list = head;
    if (!head)
        return head;
    if (!head->next)
    {
        free(head);
        return NULL;
    }
    for ( ; list->next; list = list->next);
    if (list->previous)
        list->previous->next = NULL;
    free(list);
    return head;
}

List *list_insert(List *head, unsigned index, int item)
{
    List *list = head, *new_item;
    unsigned i;
    if (!head && index)
        return head;
    if (!head || !index)
        return list_add(head, item);
    for (i = 0; i < index-1; i++)
    {
        list = list->next;
        if (!list)
            return head;
    }
    new_item = (List *) malloc(sizeof(List));
    new_item->item = item;
    new_item->next = list->next;
    new_item->previous = list;
    if (list->next)
        list->next->previous = new_item;
    list->next = new_item;
    return head;
}

int list_get(List *list, unsigned index)
{
    unsigned i;
    for (i = 0; list; list = list->next, i++)
        if (i == index)
            return list->item;
    return -1;
}

void list_set(List *list, unsigned index, int item)
{
    unsigned i;
    for (i = 0; list; list = list->next, i++)
        if (i == index)
        {
            list->item = item;
            return;
        }
}

int list_find(List *list, int item)
{
    unsigned i;
    for (i = 0; list; list = list->next, i++)
        if (list->item == item)
            return i;
    return -1;
}

unsigned list_size(List *list)
{
    unsigned i;
    for(i = 0; list; list = list->next, i++);
    return i;
}
