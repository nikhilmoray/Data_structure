#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <forward_list>


using namespace std;

struct node
{
    int data;
    struct node *next;

};

void insert(struct node **head, int data)
{
    struct node* newnode = (struct node *) calloc(1, sizeof(struct node));
    
    newnode->data = data;
    
    if(*head == NULL)
    {
        *head = newnode;
        newnode->next = NULL;
    }
    else
    {
      newnode->next = *head;
      *head = newnode;
    }
}

void printlist(struct node *head)
{
    struct node *tmp = head;
    
    while(tmp != NULL)
    {
        printf("##%d\t", tmp->data);
        tmp = tmp->next;
    }

    printf("\n");
    
}

struct node *addlist(struct node *first, struct node *sec)
{
	struct node *tmp1 = first;
	struct node *tmp2 = sec;
	struct node *sumhead = NULL;
	int carry = 0, sum = 0;
	
	while(tmp1 != NULL || tmp2 != NULL)
	{
		sum = carry + (tmp1 ? tmp1->data : 0) + (tmp2 ? tmp2->data : 0);

		carry = (sum >= 10) ? (sum / 10) : 0;

		sum = sum % 10;

		insert(&sumhead, sum);

		if(tmp1)
			tmp1 = tmp1->next;
		if(tmp2)
			tmp2 = tmp2->next;
	}

	if(carry)
		insert(&sumhead, carry);

	return sumhead;
}


int main(void)
{
	struct node *first = NULL;
	struct node *second = NULL;
	struct node *sumhead = NULL;

	insert(&first, 8);
	insert(&first, 8);
	insert(&first, 8);

	printlist(first);
	printf("############\n");
	insert(&second, 8);
	insert(&second, 8);
	insert(&second, 8);
	printlist(first);
	printf("############\n");

	sumhead = addlist(first, second);

	printlist(sumhead);


	return 0;
}
