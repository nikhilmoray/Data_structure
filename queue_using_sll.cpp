#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct node
{
    int data;
    struct node *next;

}*head, *tail;


void insert(int data)
{
    struct node *ptr = new struct node;
    ptr->data = data;
    ptr->next = NULL;

    if(head == NULL)
    {
        head = tail = ptr;
    }
    else
    {
        tail->next = ptr;
        tail = ptr;
    }
}

void printlist(void)
{
    struct node *curr = head;

    while(curr != NULL)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
}


int main() {
  
    insert(1);
    insert(2);
    insert(3);

    printlist();

   return 0;
}
