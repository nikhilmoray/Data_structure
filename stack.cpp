#include <iostream>
using namespace std;


struct stack
{
    void *data;
    struct stack *next;

} *head;


void pushdata(void *data)
{
    struct stack *ptr = new (struct stack);
    ptr->data = data;
    ptr->next = NULL;

    if(head == NULL)
        head = ptr;
    else
    {
        ptr->next = head;
        head = ptr;
    }
}

struct stack *popdata(void)
{
    struct stack *curr = head;
    struct stack *popnode = NULL;

    if(curr != NULL)
    {
        popnode = new (struct stack);

        memcpy(popnode, curr, sizeof(struct stack));

        free(curr);

        head = head->next;
    }

    return popnode;
}

void printstack(void)
{
    struct stack *curr = head;

    while(curr != NULL)
    {
        cout << *((int*)(curr->data)) << endl;
        curr = curr->next;
    }
}

int main() {

    int a = 2;
    int b = 3;
    int c = 6;
    
    pushdata(&a);
    pushdata(&b);
    pushdata(&c);

    (void)popdata();
    printstack();



   
   return 0;
}

