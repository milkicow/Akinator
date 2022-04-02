#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

#define LOX  printf("повезло повезло %d\n", __LINE__);     
#undef LOX   
#define LOX              

typedef char* DATA;
#define elem_t "%s"

struct node
{
    DATA data;
    node * left_son;
    node * right_son;
    node * parent;
};

node * TreeCtor(struct node ** nd, DATA arg);
void TreeDtor(struct node * nd);
node * TreeAdd(node * parent, node ** nd, DATA arg);
node * TreeNodeAdd(node * parent, node ** nd, DATA arg);
void TreePrintPreOrder(FILE * fp, node * nd, int n);
void TreePrintInOrder(node * nd);
void TreePrintPostOrder(node * nd);
void TreeFDump(node * nd);
void TreePrint(node * nd, FILE * fp);
void TreeSegDtor(node * nd);
node * TreeFind(node * root, int value);
void TreeScanf(FILE * fp, node ** nd, node * parent);
void Akinator(char * FILE_name);
void NewCharachter(node * node);
//node * TreeFileCtor(FILE * fp, node * korney);