#include <iostream>

using namespace std;

struct node {

    char data;
    struct node *next;

};

void printlist(struct node *head);
void reverse(struct node **head);

int size = 0;

void insert(char data, struct node **head)
{
    struct node *ptr = new struct node;

    ptr->next = NULL;
    ptr->data = data;
    if(*head == NULL)
    {
        *head = ptr;
    }
    else
    {
        ptr->next = *head;
        *head = ptr;
    }

    size++;
}

void reverseknode(int numofnoderev, struct node **head)
{
    struct node *curr = *head;
    //prev node used for dividing the list
    struct node *prev = NULL;
    //find number of sublists
    int numoflists = size/numofnoderev;
    // Create an array to hold heads of those sublists
    struct node *headarr[numoflists];

    // Number of nodes to be reversed or number of nodes 
    // per sublist
    int k = numofnoderev;
    int i = 0;

    // Init with first head
    headarr[0] = curr;

    ///////////////DIVIDE LIST////////////////////
    // Loop from 1st to last and create "numoflists" many lists
    while(curr != NULL)
    {
        // loop till K is not reaching to 0
        if(k < 1)
        {
            // Go to next index to store new head
            i++;
            // Store new head
            headarr[i] = curr;
            // break the list
            prev->next = NULL;
            // Reset the node counter
            k = numofnoderev;
        }  
        else
        {
            --k;
            prev = curr;
            curr = curr->next;
        }        
    }
    ////////////////REVERSE LIST///////////////////

    // Reverse all the sublists
    for (int i = 0; i < numoflists; ++i)
    {
        reverse(&headarr[i]);
    }

    ///////////////REATTACH LIST////////////////////

    // Join the sublists one after another
    for (int i = 0; i < numoflists; ++i)
    {
        struct node *tmphead = headarr[i];
        
        // Loop till last node (not till NULL)
        while(tmphead->next != NULL)
            tmphead = tmphead->next;

        // Check if "i" is not exceeding the numoflists as
        // we have to assign headarr[i+1] to the next pointer
        if((i+1) != numoflists)
            tmphead->next = headarr[i+1];
    }
    
    // Update the new head
    *head = headarr[0]; 
}

void reverse(struct node **head)
{
    struct node *curr = *head;
    struct node *prev = NULL;
    struct node *nxt = NULL;

    while(curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    *head = prev;

}

void printlist(struct node *head)
{
    struct node *curr = head;
    while(curr != NULL)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
}

int main(void)
{
    struct node *a = NULL, *b = NULL;

    insert('A', &a);
    insert('B', &a);
    insert('C', &a);
    insert('D', &a);
    insert('E', &a);
    insert('F', &a);

    printlist(a);
    cout << "########" << endl;

    reverseknode(3, &a);

    printlist(a);



    return 0;
}





