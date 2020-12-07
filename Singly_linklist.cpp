#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;

}*head;

void insert(int data)
{
    struct node* newnode = (struct node *) calloc(1, sizeof(struct node));
    
    newnode->data = data;
    
    if(head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
    }
    else
    {
      #if 0
      newnode->next = head;
      head = newnode;
      #else
      struct node *last = head;
      while(last->next != NULL)
        last = last->next;

      last->next = newnode;
      #endif
    }
}

/* Insert with recurrtion */
void insert(struct node **ptr, int data)
{
    if(*ptr == NULL)
    {
        struct node *newnode = new (struct node);
        newnode->next = NULL;
        newnode->data = data;

        *ptr = newnode;
    }
    else
    {
        insert((&(*ptr)->next), data);
    }
}


struct node *newnode(int data)
{
    struct node *curr = new struct node;

    curr->data = data;
    curr->next = NULL;
    return curr;
}


void insertatN(int data, int pos)
{
    struct node *curr = head;

    // Insert at head 
    if(!pos && curr)
    {
        struct node *curr = newnode(data);
        curr->next = head;
        head = curr;
    }
    // Insert rest wehere
    else
    {
        // Go one step back to get the exact pos
        --pos;
        while(pos)
        {
            --pos;
            if(curr != NULL)
                curr = curr->next;
            else
                return;
        }

        struct node *tmp = curr->next;
        curr->next = newnode(data);
        curr->next->next = tmp;
    }
}



bool deletenode(int data)
{
    char ret = 1, flag = 0;
    struct node *prev = NULL;
    struct node *tmphead = head;
    
    while(tmphead != NULL)
    {
        if(tmphead->data == data)
        {
            if(prev != NULL)
                prev->next = tmphead->next;
            else
            head = tmphead->next;
            
            flag = 1;
        }
        
        prev = tmphead;
        tmphead = tmphead->next;
    }
    
    if(flag)
    ret = 0;
    
    return ret;
}

void reverselist(void)
{
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *nxt = NULL;
    
    while(curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    
    head = prev;
}

struct node *reverseklist(struct node *head, int k)
{
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *nxt = NULL;
    int i = k;
    
    while(curr != NULL && i > 0)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;

        --i;
    }

    if(nxt)
    head->next = reverseklist(nxt, k);
    
    return prev;

}

void printlist(void)
{
    struct node *tmp = head;
    
    while(tmp != NULL)
    {
        printf("##%d\n", tmp->data);
        tmp = tmp->next;
    }
    
}

int findmiddle(void)
{
    struct node *fastptr = head;
    struct node *slowptr = head;    
    
    while(fastptr != NULL && fastptr->next != NULL)
   {
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
   }
   
   return slowptr->data;
}

struct node *findloop(void)
{
    struct node *fastptr = head;
    struct node *slowptr = head;
    int flag = 0;   
    
    while(fastptr->next != NULL)
    {
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
        
        if(fastptr == slowptr)
        {
            flag = 1;
            break;    
        }
        
   }
   
   if(!flag)
        slowptr = NULL;

   return slowptr;
}


void addloop(void)
{
    struct node *tmp = head;
    
    while(tmp != NULL)
    {
        if(tmp->data == 4)
        {
            tmp->next = head;
            break;
        }
        
        tmp = tmp->next;
    }
}


void removeloop(void)
{
    struct node *loopnode = findloop();
    
    struct node *tmp = loopnode;
        
    while(tmp->next != loopnode)
    {
        tmp = tmp->next;   
    }
    
    tmp->next = NULL;
}


void listsort(void)
{
  struct node *curr = head;
  struct node *currplus = NULL;

  while(curr != NULL)
  {
    currplus = curr->next;
    
    while(currplus != NULL)
    {
      if(curr->data > currplus->data)
      {
        int tmp = curr->data;
        curr->data = currplus->data;
        currplus->data = tmp;
      }

      currplus = currplus->next;
    }

    curr = curr->next;
  }
}

int main() {
    
    int delnum;
    
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    
    printlist();

    printf("##########\n");
    insertatN(6, 2);
    printlist();

    deletenode(1);
    
    reverselist();
    printf("\n\n");
    
    printlist();
    
    delnum = findmiddle();
    
    printf("MIDDLE : %d\n", delnum);
    
    /* Added for testing purpose */
    addloop();
    
    struct node *loopnode = findloop();
    printf("LoopNode : %d\n", loopnode->data);

    removeloop();
    printlist();

    
    return 0;
}

