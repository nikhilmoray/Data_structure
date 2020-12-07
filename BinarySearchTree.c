#include <iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

/* node struct prototype */
struct node
{
  int data;                 ///< Data

  struct node *lchild;     ///< Left node pointer
  struct node *rchild;     ///< Right node pointer

} node_t;


void insert(struct node **rootnode, int data)
{
    if(NULL == (*rootnode))
    {
        struct node *newnode = (struct node *) calloc(1, sizeof(struct node));

        newnode->lchild = NULL;
        newnode->rchild = NULL;
        newnode->data = data;

        *rootnode = newnode;
    }
    else if(data < (*rootnode)->data)
    {
        insert(&((*rootnode)->lchild), data);
    }

    else if(data > (*rootnode)->data)
    {
        insert(&((*rootnode)->rchild), data);
    }
}


struct node *search(struct node **rootnode, struct node **parentnode, int data)
{
    struct node *currentnode = NULL;

    if(NULL != (*rootnode))
    {
        if(data < (*rootnode)->data)
        {
            *parentnode = *rootnode;
            currentnode = search(&((*rootnode)->lchild), parentnode, data);
        }
        else if(data > (*rootnode)->data)
        {
            *parentnode = *rootnode;
            currentnode = search(&((*rootnode)->rchild), parentnode, data);
        }
        else
        {
            currentnode = *rootnode;
        }
    }
    return currentnode;
}


void printinorder(struct node **rootnode)
{
    if(NULL != (*rootnode))
    {
        printinorder(&(*rootnode)->lchild);
        printf("%d\n", (*rootnode)->data);
        printinorder(&(*rootnode)->rchild);
    }
}


void printpreorder(struct node **rootnode)
{
    if(NULL != (*rootnode))
    {
        printf("%d\n", (*rootnode)->data);
        printinorder(&(*rootnode)->lchild);
        printinorder(&(*rootnode)->rchild);
    }
}


void printpostorder(struct node **rootnode)
{
    if(NULL != (*rootnode))
    {
        printinorder(&(*rootnode)->lchild);
        printinorder(&(*rootnode)->rchild);
        printf("%d\n", (*rootnode)->data);
    }
}


struct node *mininode(struct node *ptr)
{
    struct node *curr = ptr;

    while(curr && curr->lchild != NULL)
        ptr = ptr->lchild;

    return curr;
}

struct node *deletenode(struct node *root, int data)
{
    if(root == NULL)
        return NULL;

    else if(data < root->data)
        root->lchild = deletenode(root->lchild, data);

    else if(data > root->data)
        root->rchild = deletenode(root->rchild, data);
    // got the node
    else
    {
        // if node is having one child or no child
        if(root->lchild == NULL)
        {
            struct node *tmp = root->rchild;
            free(root);
            return tmp;
        }
        else if(root->rchild == NULL)
        {
            struct node *tmp = root->lchild;
            free(root);
            return tmp;
        }
        else
        {
            // replace the current node with inorder successor
            struct node *tmp = mininode(root->rchild);
            root->data = tmp->data;

            // delete inorder successor
            root->rchild = deletenode(root->rchild, root->data);
        }
    }

    return root;
}


// Convert a BST to a Binary Tree such that sum of all greater 
// keys are added to every key
void bstsum(struct node *root, int *sum)
{
    if(root == NULL)
        return;
    
    bstsum(root->rchild, sum);

    *sum = *sum + root->data;

    root->data = *sum;

    bstsum(root->lchild, sum);
}



//Convert a given Binary Tree to Doubly Linked List 
struct node *head = NULL;
void bst2doubly(struct node *root)
{
    static struct node *pre = NULL;

    if(root == NULL)
        return;

    bst2doubly(root->lchild);

    if(pre == NULL)
        head = root;
    else
    {
        pre->rchild = root;
        root->lchild = pre;
    }

    pre = root;

    bst2doubly(root->rchild);
}

// Print doubly list
void printlist(void)
{
    struct node *curr = head;

    while(curr != NULL)
    {
        cout << curr->data << endl;
        curr = curr->rchild;
    }
}

int main(int argc, char const *argv[])
{
    struct node *root, *parent, *current;

    insert(&root, 6);
    insert(&root, 4);
    insert(&root, 1);
    insert(&root, 3);
    insert(&root, 5);

    printinorder(&root);

    deletenode(root, 6);

    printf("####\n");
    printinorder(&root);

    
    return 0;
}
