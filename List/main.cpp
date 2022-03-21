#include "header.h"

int main()
{
    struct list sp = {};
    int list_capacity = 1;

    ListCtor(&sp, list_capacity);


    ListInsert(&sp, 0, 11);

    ListInsert(&sp, 0, 13);


    ListInsert(&sp, 0, 14);

    //ListInsert(&sp, 3, 314); - test ListResize vv

    ListFDump(&sp);

    ListDtor(&sp);

    return 0;
}