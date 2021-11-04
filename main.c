#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    long int value;
    struct Node *next;
    struct Node *previous;
};

struct Node* head;
char **array;
long int read_lines;

void UserInput();
int isEmpty();
void freeAll();
long int DROPReturn();
void pushToTopOfStack(long int input);
int checkIfListMoreThanTwo();
void printa();


/*INPUT / OUTPUT*/
void IN();
void OUT();

/*STACK OPERATIONS*/
void DROP();
void LIT(long int input);
void SWAP();
void DUP(long int value);

/*INTEGER OPERATORS*/
void ADD();
void SUB();
void MUL();
void DIV();
void MOD();
void AND();
void OR();

/*Branching*/
int IFLT();
long int IFEQ();

/*FILE STUFF*/
void read_from_file();
void AllocateArray();

int main() {

    UserInput();
    freeAll();
    free(array);

    return 0;
}

void UserInput()
{
    AllocateArray();
    read_from_file();

    long int counter = 0;

    while(counter != read_lines)
    {
        char oper[] = " ";
        long int x = 0;

        char temp[999];
        strcpy(temp,array[counter]);
        char *ptr = strtok(temp,oper);

        if(ptr != NULL)
        {
            char *se = strtok(NULL,oper);
            if(se != NULL)
            {
                 x = strtol(se, NULL, 10);

            }

        }
        /*gets rid of the \n*/
        char *p = strchr(ptr, '\n');
        if(p != NULL)
        {
            *p = '\0';
        }

        /*Enter the In Function*/
        if(strcmp(ptr, "OUT") == 0)
        {
            OUT();
        }
        else if(strcmp(ptr, "IN") == 0)
        {
            IN();
        }
        else if(strcmp(ptr, "DROP") == 0)
        {
            DROP();
        }
        else if(strcmp(ptr, "LIT") == 0)
        {
            LIT(x);
        }
        else if(strcmp(ptr, "ADD") == 0)
        {
            ADD();
        }
        else if(strcmp(ptr, "SUB") == 0)
        {
            SUB();
        }
        else if(strcmp(ptr, "MUL") == 0)
        {
            MUL();
        }
        else if(strcmp(ptr, "DIV") == 0)
        {
            DIV();
        }
        else if(strcmp(ptr, "MOD") == 0)
        {
            MOD();
        }
        else if(strcmp(ptr, "AND") == 0)
        {
            AND();
        }
        else if(strcmp(ptr, "OR") == 0)
        {
            OR();
        }
        else if(strcmp(ptr, "SWAP") == 0)
        {
            SWAP();
        }
        else if(strcmp(ptr, "DUP") == 0)
        {

            DUP(x);
        }
        else if(strcmp(ptr, "IFEQ") == 0)
        {
            if(IFEQ() == 1)
            {
                counter = x;
                counter = counter - 2;
            }
        }
        else if(strcmp(ptr, "IFLT") == 0)
        {
            if(IFLT() == 1)
            {
                counter = x;
                counter = counter - 2;
            }
        }
        else if(strcmp(ptr, "JUMP") == 0)
        {
            counter = x;
            counter = counter - 2;
        }

        counter++;
        printa();
    }

}

void IN()
{
    char *ptr;
    long int input;
    char get[4096];

    printf("Enter an integer: ");
    fgets(get, 100, stdin);
    input = strtol(get, &ptr, 10);

    //Initialize the first head
    pushToTopOfStack(input);

}

/*PUSH A NEW NODE TO THE TOP OF THE STACK*/
void pushToTopOfStack(long int input)
{
    if(isEmpty() == 0)
    {
        struct Node* temp;
        temp = malloc(sizeof(*temp));
        head = temp;

        head->value = input;
        head->previous = NULL;
        head->next = NULL;
    }
    else
    {
        struct Node* new;
        struct Node *tempy;
        new = malloc(sizeof(*new));
        tempy = head;

        /*look through the whole stack
         * and find the top of the stack*/
        while(tempy->next != NULL)
        {
            tempy = tempy->next;
        }

        /*creates the new node*/
        new->value = input;
        new->next = NULL;
        new->previous = tempy;
        (new->previous)->next = new;
    }

}



/*pops the top of the stack and then print it*/
void OUT()
{
    if(isEmpty() == 0)
    {
        printf("List is empty\n");
    }
    else if(head->next != NULL)
    {
        struct Node* temp;
        temp = head;

        /*look through the whole stack
         * and find the top of the stack*/
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        /*pop the stack*/
        (temp->previous)->next = NULL;
        temp->next = NULL;
        printf("Poped out %ld\n", temp->value);
        free(temp);
    }
    else
    {
        /*pop the head*/
        printf("Poped out %ld\n", head->value);

        free(head);
        head = NULL;
    }

}

/*POPS THE TWO TOP ELEMENTS IN TEH STACK AND THEN ADDS THEM
 * THEN PUSHES THE RESULT ONTO THE STACK*/
void ADD()
{
    if(checkIfListMoreThanTwo() < 2)
    {
        printf("List is empty or has only 1 element\n");
    }
    else
    {

        /*get the top two nodes*/
        long int node1 = DROPReturn();
        long int node2 = DROPReturn();

        long int total;

        total = node1 + node2;
        pushToTopOfStack(total);
    }
}

/*POPS THE TWO TOP ELEMENTS IN TEH STACK AND THEN SUBTRACTS THEM
 * THEN PUSHES THE RESULT ONTO THE STACK*/
void SUB()
{
    if(checkIfListMoreThanTwo() < 2)
    {
        printf("List is empty or has only 1 element\n");
    }
    else
    {

        /*get the top two nodes*/
        long int node1 = DROPReturn();
        long int node2 = DROPReturn();

        long int total;

        total = node1 - node2;
        pushToTopOfStack(total);

    }
}

/*POPS THE TWO TOP ELEMENTS IN TEH STACK AND THEN MULTIPLIES THEM
 * THEN PUSHES THE RESULT ONTO THE STACK*/
void MUL()
{
    if(checkIfListMoreThanTwo() < 2)
    {
        printf("List is empty or has only 1 element\n");
    }
    else
    {
        /*get the top two nodes*/
       long int node1 = DROPReturn();
       long int node2 = DROPReturn();

       long int total;

       total = node1 * node2;
       pushToTopOfStack(total);
    }
}

/*POPS THE TWO TOP ELEMENTS IN TEH STACK AND THEN DIVIDES THEM
 * THEN PUSHES THE RESULT ONTO THE STACK*/
void DIV()
{
    if(checkIfListMoreThanTwo() < 2)
    {
        printf("List is empty or has only 1 element\n");
    }
    else
    {
        //struct Node* node1;
        //struct Node* node2;

        /*get the top two nodes*/
        long int node1 = DROPReturn();
        long int node2 = DROPReturn();

        long int total;

        total = node1 / node2;
        pushToTopOfStack(total);
    }
}

/*POPS THE TWO TOP ELEMENTS IN TEH STACK AND THEN MODS THEM
 * THEN PUSHES THE RESULT ONTO THE STACK*/
void MOD()
{
    if(checkIfListMoreThanTwo() < 2)
    {
        printf("List is empty or has only 1 element\n");
    }
    else
    {
        //struct Node* node1;
        //struct Node* node2;

        /*get the top two nodes*/
        long int node1 = DROPReturn();
        long int node2 = DROPReturn();

        long int total;

        total = node1 % node2;
        pushToTopOfStack(total);
    }
}

/*POPS THE TWO TOP ELEMENTS OF THE STACK, OPERATES THE AND BITWISE
 * THEN PUSHES THE RESULT*/
void AND()
{
    if(checkIfListMoreThanTwo() < 2)
    {
        printf("List is empty or has only 1 element\n");
    }
    else
    {
        //struct Node* node1;
        //struct Node* node2;

        /*get the top two nodes*/
        long int node1 = DROPReturn();
        long int node2 = DROPReturn();

        long int total;

        total = (unsigned int)node1 & (unsigned int)node2;
        pushToTopOfStack(total);
    }
}

/*POPS THE TWO TOP ELEMENTS OF THE STACK, OPERATES THE AND BITWISE
 * THEN PUSHES THE RESULT*/
void OR()
{
    if(checkIfListMoreThanTwo() < 2)
    {
        printf("List is empty or has only 1 element\n");
    }
    else
    {
        //struct Node* node1;
        //struct Node* node2;

        /*get the top two nodes*/
        long int node1 = DROPReturn();
        long int node2 = DROPReturn();

        long int total;

        total = (unsigned int)node1 | (unsigned int)node2;
        pushToTopOfStack(total);
    }
}

/*same as OUT but doesnt print the value and returns a int*/
long int DROPReturn()
{

    if(head->next != NULL)
    {
        struct Node* temp;
        temp = head;

        /*look through the whole stack
         * and find the top of the stack*/
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        /*pop the stack*/
        long int ret = temp->value;
        (temp->previous)->next = NULL;
        temp->next = NULL;
        temp->previous = NULL;
        free(temp);
        return  ret;
    }
    else
    {
        /*pop the head*/
        long int ret = head->value;
        head->next = NULL;
        head->previous = NULL;
        free(head);
        head = NULL;
        return ret;
    }

}

/*drop the top element of the stack */
void DROP()
{
    if(isEmpty() == 0)
    {
        printf("List is empty\n");
    }
    else if(head->next != NULL)
    {
        struct Node* temp;
        temp = head;

        /*look through the whole stack
         * and find the top of the stack*/
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        /*pop the stack*/
        temp->value = '\0';
        (temp->previous)->next = NULL;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        /*pop the head*/
        head->value = '\0';
        head->next = NULL;
        head->previous = NULL;
        free(head);
        head = NULL;
    }

}

/*LIT[NUMBER] pushes it on top of the stack with the input being the value*/
void LIT(long int input)
{
    //Initialize the first head
    pushToTopOfStack(input);


}

/*DUPLICATE THE TOP N ELEMENTS OF THE STACK*/
void DUP(long int value)
{
    if(checkIfListMoreThanTwo() >= value || checkIfListMoreThanTwo() == 0)
    {
        struct Node* temp;

        temp = head;

        /*take temp to the top of the node*/
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        /*go down the stack so we can duplicate in order*/
        int counter = 1;
        while(counter != value)
        {
            if(temp->previous != NULL)
            {
                temp = temp->previous;
            }
            counter++;
        }

        /*this duplicates the stack in order*/
        for(int i =0; i <= value - 1; i++)
        {
            pushToTopOfStack(temp->value);
            temp = temp->next;
        }

    }
    else
    {
        printf("Not enough elements in the stack to duplicate\n");
    }
}

/*SWAPS THE TOP TWO ELEMENTS OF THE STACK*/
void SWAP()
{
    if(checkIfListMoreThanTwo() >= 2)
    {
        struct Node* temp;

        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        long int store = temp->value;
        /*swap the top 2 elements of the stack*/
        temp->value = (temp->previous)->value;
        (temp->previous)->value = store;

    }

}

/*checks if the top two elements are equal, if so the jump to the given intructions
 * regardless pop the two top elements*/
long int IFEQ()
{
    struct Node* temp;
    long int x;

    temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }


    if(temp->value == (temp->previous)->value)
    {
        x = 1;
        DROP();
        DROP();
        return x; //returns 1 if it is true
    }
    else
    {
        x = 0;
        DROP();
        DROP();
        return x;
    }

}

/*checks if the first element of the stack is less then the second if so the jump to the given intructions
 * regardless pop the two top elements*/
int IFLT()
{
    struct Node* temp;

    temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    if(temp->value < (temp->previous)->value)
    {
        DROP();
        DROP();
        return 1; //returns 1 if it is true

    }
    else
    {
        DROP();
        DROP();
        return -1;
    }


}

/*check if the list is empty*/
int isEmpty()
{
    if(head != NULL)
    {
        return 1; //True, stack is not empty
    }
    else
    {
        return 0; //False, stack is empty
    }
}

/*free the whole list of nodes*/
void freeAll()
{
    struct Node* temp;

        while(head != NULL)
        {
            printf("hello");
            temp = head;
            head = head->next;
            free(temp);
        }

    for(int i = 0; i < read_lines; i++)
    {
        if(array[i] != NULL)
        {
            free(array[i]);
        }
    }
}

/*check if the list how many nodes it has*/
int checkIfListMoreThanTwo()
{
    struct Node* temp;
    temp = head;
    int v = 0;

    /*look through the whole stack
     * and find the top of the stack*/
    while(temp != NULL)
    {
        v++;
        temp = temp->next;
    }
    return v;
}

void printa()
{
    struct Node* temp;
    temp = head;

    /*look through the whole stack
     * and find the top of the stack*/
    while(temp != NULL)
    {
        printf("%ld ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void AllocateArray()
{
    char test[255];
    char* ptr;
    FILE *file = fopen("/home/nazar/Desktop/miniproject2.txt", "r");
    //fscanf(file, "%d",&read_lines);

    /*reads the first line of the file*/
    fgets(test, sizeof(test), file);
    read_lines = strtol(test, &ptr, 10);

    /*allocate the memory of the array*/
    array = malloc((read_lines + 1) * sizeof(char *));
    fclose(file);
}

/*READ FROM FILE AND STORE ALL OF ITS INPUTS INTO AN ARRAY*/
void read_from_file()
{
    char test[255];

    FILE *file = fopen("/home/nazar/Desktop/miniproject2.txt", "r");

    if(file == NULL)
    {
        exit(1);
    }
    else
    {
        /*fgets that gets rid of the integer
         * in the beginning of the file so we dont
         * put it in our array*/
        fgets(test, sizeof(test),file);

        /*loop */
        for(int i = 0; i < read_lines;i++)
        {
            if(fgets(test, sizeof(test),file) != NULL)
            {
                array[i] = (char *)malloc(read_lines + 1);
                strcpy(array[i], test);
            }
        }
        fclose(file);
    }

}

