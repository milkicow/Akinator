#include "header.h"

node * TreeCtor(node ** nd, DATA arg)
{
    LOX
    const int arg_size = 25;
    *nd = (node *) calloc(1, sizeof(node));
    (*nd) -> data = (char *) calloc(arg_size, sizeof(char));

    assert(nd);
    assert((*nd) -> data);
    (*nd) -> data = arg;
    //(*nd) -> data = arg;

    (*nd) -> left_son = NULL;
    (*nd) -> right_son = NULL;

    return *nd;
}

void TreeDtor(node * nd)  //дерево и его поддерево
{   
    if(nd != NULL)
    {   
        LOX
        TreeDtor(nd -> left_son);
        TreeDtor(nd -> right_son);

        free(nd -> data);
        free(nd);
    }
}

node * TreeAdd(node * parent, node ** nd, DATA arg)
{   
    LOX
    if(*nd == NULL)
    {   
        LOX
        TreeNodeAdd(parent, nd, arg);
    }
    else
    {   
        if (arg < (*nd) -> data)
        {   
            LOX
            TreeAdd(*nd, &((*nd) -> left_son), arg);
            LOX
        }
        else if (arg > (*nd) -> data)
        {   
            LOX
            TreeAdd(*nd, &((*nd) -> right_son), arg);
        }
    }
    return *nd;
}

node * TreeNodeAdd(node * parent, node ** nd, DATA arg)
{    
    LOX
    const int arg_size = 20;
    *nd = (node *) calloc(1, sizeof(node));
    (*nd) -> data = (char *) calloc(arg_size, sizeof(char));

    assert(nd);
    assert((*nd) -> data);

    (*nd) -> data = arg;
    LOX
    (*nd) -> left_son = NULL;
    LOX
    (*nd) -> right_son = NULL;
    LOX
    (*nd) -> parent = parent;
    LOX

    return *nd;
}

void TreePrintPreOrder(FILE * fp, node * nd, int n)
{   
    assert(fp);
    assert(nd);
    fprintf(fp, "\n%*s", n, "{");

    fprintf(fp, " " elem_t, nd -> data);

    if(nd -> left_son) TreePrintPreOrder(fp, nd -> left_son, n + 4);
    //else n = 2;
    if(nd -> right_son) TreePrintPreOrder(fp, nd -> right_son, n + 4);
    //else n = 2;
    if(!nd -> left_son && !nd -> right_son) n = 2;

    fprintf(fp, "%*s\n", n, "}");
}

void TreePrintInOrder(node * nd)
{
    if (nd == NULL)
    {   
        return;
    }
    //printf("%*s", n, "{");

    TreePrintInOrder(nd -> left_son);
    printf(" " elem_t, nd -> data);
    TreePrintInOrder(nd -> right_son);

    //printf("%s", "}");
}

void TreePrintPostOrder(node * nd)
{
    if (nd == NULL)
    {   
        return;
    }
    TreePrintPostOrder(nd -> left_son);
    TreePrintPostOrder(nd -> right_son);
    printf(" " elem_t, nd -> data);
}

void TreeFDump(node * nd)
{   
    LOX
    FILE * fp = fopen("dump.txt", "w");
    assert(fp);

    fprintf(fp, "digraph G {\n");
    fprintf(fp, "rankdir=UD;\n");
    LOX
    TreePrint(nd, fp);

    fprintf(fp, "}\n");
    fclose(fp);
    system("dot dump.txt -T pdf -o dump.pdf");
    system("open dump.pdf");
}

void TreePrint(node * nd, FILE * fp)
{   
    LOX
    if(nd == NULL)
    {   
        LOX
        return;
    }
        
    fprintf(fp, "node%p [shape=record,label=\"" elem_t " \" ];\n", nd, nd -> data);
    if(nd -> left_son != NULL)
    {
        LOX
        fprintf(fp, "node%p -> node%p[color = green];\n", nd , nd -> left_son );
        TreePrint(nd -> left_son, fp);
    }
    if(nd -> right_son != NULL)
    {
        LOX
        fprintf(fp, "node%p -> node%p[color = red];\n", nd , nd -> right_son);
        TreePrint(nd -> right_son, fp);
    }
}

node * TreeFind(node * root, DATA value)
{   
    assert(root);
    assert(value);

    node * nd = root;
    while(nd)
    {
        if(nd -> data == value) 
            return nd;
        if(nd -> data < value)
            nd = nd -> right_son;
        if(nd -> data > value)
            nd = nd -> left_son;
    }

    return NULL;
}

void TreeSegDtor(node * nd)
{
    assert(nd);

    nd -> right_son = NULL;
    nd -> left_son = NULL;
}

void TreeScanf(FILE * fp, node ** nd, node * parent)
{   
    LOX
    const int arg_size = 20;
    char * data = (char *) calloc(arg_size, sizeof(char));
    assert(data);

    char bracket[2];
    LOX
    fscanf(fp, "%s", bracket);
    LOX
    if(strcmp(bracket, "{") == 0)
    {   
        LOX
        fscanf(fp, elem_t, data);

        LOX
        TreeNodeAdd(parent, nd, data);
        //for(int i = 0; i < 20; i++) data[i] = 0;  ?
        LOX
        TreeScanf(fp, &((*nd) -> left_son), *nd);
        LOX
        TreeScanf(fp, &((*nd) -> right_son), *nd);
    }
    else if(strcmp(bracket, "}") == 0)
    {   
        LOX
        ungetc('}', fp);
        return;
    }
    fscanf(fp, "%s", bracket);       
}

void Akinator(char * FILE_name)
{   
    system("clear");
    printf("\tЯ Siri - могу отгадать кого угодно!\n");   
    system("say \"Я Siri - могу отгадать кого угодно!\"");
    printf("\tЗагадай персонажа, а я буду задавать тебе вопросы.\n\n");
    system("say \"Загадай персонажа, а я буду задавать тебе вопросы.\"");
    printf("\tДля продолжения нажмите любую кнопку\n");
    getchar();

    //LOX
    node * nd = NULL;
    node * korney = NULL;
    FILE * fp = fopen(FILE_name, "r");
    const int arg_size = 40;
    char * guess = (char *) calloc(arg_size, sizeof(char));
    char * word = (char *) calloc(arg_size + 10, sizeof(char));

    assert(fp);
    LOX
    TreeScanf(fp, &nd, NULL);
    fclose(fp);

    korney = nd;
    char answer[10] = "";

    while(nd -> right_son && nd -> left_son)
    {   
        system("clear");

        strcpy(word, "say \"это ");
        strcpy(guess, nd -> data);
        printf("\tэто %s?\n", nd -> data);

        strcat(guess, "\"");

        strcat(word, guess);
        system(word);
        printf("%s\n", word);
        
        scanf("%s", answer);
        if(strcmp(answer, "да") == 0)
        {
            LOX
            nd = nd -> left_son;
        }
        if(strcmp(answer, "нет") == 0)
        {   
            LOX
            nd = nd -> right_son;
        }
    }
    system("clear");

    strcpy(word, "say \"это ");
    strcpy(guess, nd -> data);
    printf("\tэто %s?\n", nd -> data);

    strcat(guess, "\"");

    strcat(word, guess);
    system(word);
    printf("%s\n", word);


    scanf("%s", answer);
        if(strcmp(answer, "да") == 0)
        {
            LOX
            printf("\tЯ знала!\n");
            system("say \"Я знала!\"");

        }
        if(strcmp(answer, "нет") == 0)
        {   
            NewCharachter(nd);
            printf("\tТеперь ты меня не обманешь!!");

        }

    fp = fopen(FILE_name, "w");
    TreePrintPreOrder(fp, korney, 4);
    TreeFDump(korney);

    fclose(fp);
    free(guess);
    free(word);
    TreeDtor(nd);
} 

void NewCharachter(node * nd)
{   
    const int ch_size = 20;
    const int dif_size = 50;
    char * charachter = (char *) calloc(ch_size, sizeof(char));
    char * different = (char *) calloc(dif_size, sizeof(char));

    printf("Кто же это ?\n"); // ДОБАВИТЬ ОЗВУЧКУ !
    scanf("%s", charachter);
    printf("Чем %s отличается от %s\n?", charachter, nd -> data);

    printf("он ");
    scanf("%s", different);

    TreeNodeAdd(nd, &(nd -> left_son), charachter);
    TreeNodeAdd(nd, &(nd -> right_son), nd -> data);

    nd -> data = different;

}