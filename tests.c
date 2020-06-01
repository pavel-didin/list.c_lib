#include "list.h"
#include <stdio.h>

int main(void)
{
    List *list = NULL;
    LIST_ERR err;

    list_destroy(list, &err);

    if(err == EEMPTY)
        fprintf(stdout, "Test_1\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_1\t->\tFAILED\n");

    list = list_insert(list, 1, 7, &err);

    if(err == ESIZE)
        fprintf(stdout, "Test_2\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_2\t->\tFAILED\n");

    list = list_delete(list, 1, &err);

    if(err == EEMPTY)
        fprintf(stdout, "Test_3\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_3\t->\tFAILED\n");

    list = list_delete_first(list, &err);

    if(err == EEMPTY)
        fprintf(stdout, "Test_4\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_4\t->\tFAILED\n");

    list = list_delete_last(list, &err);

    if(err == EEMPTY)
        fprintf(stdout, "Test_5\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_5\t->\tFAILED\n");

    list_get(list, 0, &err);

    if(err == EEMPTY)
        fprintf(stdout, "Test_6\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_6\t->\tFAILED\n");

    list_set(list, 0, 4, &err);

    if(err == EEMPTY)
        fprintf(stdout, "Test_7\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_7\t->\tFAILED\n");

    list_find(list, 97, &err);

    if(err == EEMPTY)
        fprintf(stdout, "Test_8\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_8\t->\tFAILED\n");

    list = list_append(list, 5, &err);

    if(err == ESUCCESS)
        fprintf(stdout, "Test_9\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_9\t->\tFAILED\n");

    list = list_append(list, 6, &err);

    if(err == ESUCCESS)
        fprintf(stdout, "Test_10\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_10\t->\tFAILED\n");

    list = list_append(list, 19, &err);

    if(err == ESUCCESS)
        fprintf(stdout, "Test_11\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_11\t->\tFAILED\n");

    list = list_append(list, 17, &err);

    if(err == ESUCCESS)
        fprintf(stdout, "Test_12\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_12\t->\tFAILED\n");

    list = list_append(list, 8, &err);

    if(err == ESUCCESS)
        fprintf(stdout, "Test_13\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_13\t->\tFAILED\n");

    list = list_add(list, 25, &err);

    if(err == ESUCCESS)
        fprintf(stdout, "Test_14\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_14\t->\tFAILED\n");

    list = list_delete(list, 100, &err);

    if(err == ESIZE)
        fprintf(stdout, "Test_15\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_15\t->\tFAILED\n");

    list_reverse_print(list, &err);

    if(err == ESUCCESS)
        fprintf(stdout, "Test_16\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_16\t->\tFAILED\n");

    list_print(list, &err);

    if(err == ESUCCESS)
        fprintf(stdout, "Test_17\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_17\t->\tFAILED\n");

    list = list_delete(list, 100, &err);

    if(err == ESIZE)
        fprintf(stdout, "Test_18\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_18\t->\tFAILED\n");

    list = list_delete(list, 2, &err);

    if(err == ESUCCESS)
        fprintf(stdout, "Test_19\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_19\t->\tFAILED\n");

    list = list_delete_first(list, &err);

    if(err == ESUCCESS)
        fprintf(stdout, "Test_20\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_20\t->\tFAILED\n");

    list = list_delete_last(list, &err);

    if(err == ESUCCESS)
        fprintf(stdout, "Test_21\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_21\t->\tFAILED\n");

    list = list_insert(list, 100, 7, &err);

    if(err == ESIZE)
        fprintf(stdout, "Test_22\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_22\t->\tFAILED\n");

    list = list_insert(list, 2, 9, &err);

    if(err == ESUCCESS)
        fprintf(stdout, "Test_23\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_23\t->\tFAILED\n");

    list_get(list, 0, &err);

    if(err == ESUCCESS)
        fprintf(stdout, "Test_24\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_24\t->\tFAILED\n");

    list_get(list, 100, &err);

    if(err == ESIZE)
        fprintf(stdout, "Test_25\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_25\t->\tFAILED\n");

    list_get(list, 2, &err);

    if(err == ESUCCESS)
        fprintf(stdout, "Test_26\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_26\t->\tFAILED\n");

    list_set(list, 100, 4, &err);

    if(err == ESIZE)
        fprintf(stdout, "Test_27\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_27\t->\tFAILED\n");

    list_set(list, 1, 99, &err);

    if(err == ESUCCESS)
        fprintf(stdout, "Test_28\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_28\t->\tFAILED\n");

    list_find(list, 97, &err);

    if(err == EFOUND)
        fprintf(stdout, "Test_29\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_29\t->\tFAILED\n");

    list_find(list, 99, &err);

    if(err == ESUCCESS)
        fprintf(stdout, "Test_30\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_30\t->\tFAILED\n");

    list_size(list, &err);

    if(err == ESUCCESS)
        fprintf(stdout, "Test_31\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_31\t->\tFAILED\n");

    list_destroy(list, &err);

    if(err == ESUCCESS)
        fprintf(stdout, "Test_32\t->\tPASSED\n");
    else
        fprintf(stdout, "Test_32\t->\tFAILED\n");

    return 0;
}