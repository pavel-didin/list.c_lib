#include "list.h"
#include <stdio.h>

int main(void)
{
	List *list = NULL;
	LIST_ERR err;

  list_append(list, 5, &err);
  
  list_append(list, 6, &err);
  
  list_append(list, 59, &err);
  
  list_append(list, 17, &err);
  
  list_append(list, 8, &err);
  
  list_add(list, 3, &err);
  
  list_destroy(list, &err);
  
  list_reverse_print(list, &err);
  
  list_print(list, &err);
  
  list_delete(list, 1, &err);
  
  list_delete_first(list, &err);
  
  list_delete_last(list, &err);
  
  list_insert(list, 1, 7, &err);
  
  prinft("%d\n", list_get(list, 0, &err));
  
  list_set(list, 1, 4, &err);
  
  printf("%d\n", list_find(list, 4, &err));
  
  printf("%u\n", list_size(list, &err));

	return 0;
}
