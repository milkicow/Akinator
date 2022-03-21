#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

#define LOX  printf("повезло повезло %d\n", __LINE__);                     



void ListCtor(struct list * sp, int list_capacity);
void ListDtor(struct list* sp);
int ListInsert(struct list* sp, int log_num, int arg);
int ListDelete(list *sp, int index);
void ListDump(list* sp);
void ListFDump(list* sp);
int ListFoundNum(list * sp, int ph_num);
void ListSort(list * sp, list * sortsp);
void ListResize(list * sp); // defolt koef = 2;

struct list
{
    int * data;
    int head;
    int tail;
    int capacity;
    int * next;
    int * prev;
    int free;
    int size;
};