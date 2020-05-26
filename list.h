#ifndef _LIST_H_
#define _LIST_H_

typedef struct List List;
struct List
{
	int item;
	List *previous;
   	List *next;
};

typedef enum {
	ESUCCESS = 0,
	EMALLOC,
	EFOUND,
	EINVARG
} LIST_ERR;

stack *init_stack(int size, LIST_ERR *err);

void remove_stack(stack *stack, LIST_ERR *err);

int pop(stack *stack, LIST_ERR *err);

void push(stack *stack, int val, LIST_ERR *err);

List *list_append(List *head, int item, LIST_ERR *err);

List *list_add(List *head, int item, LIST_ERR *err);

void list_destroy(List *list, LIST_ERR *err);

void list_reverse_print(List *head, LIST_ERR *err);

void list_print(List *head, LIST_ERR *err);

List *list_delete(List *head, unsigned index, LIST_ERR *err);

List *list_delete_first(List *head, LIST_ERR *err);

List *list_delete_last(List *head, LIST_ERR *err);

List *list_insert(List *head, unsigned index, int item, LIST_ERR *err);

int list_get(List *list, unsigned index, LIST_ERR *err);

void list_set(List *list, unsigned index, int item, LIST_ERR *err);

int list_find(List *list, int item, LIST_ERR *err);

unsigned list_size(List *list, LIST_ERR *err);

#endif	// _LIST_H_
