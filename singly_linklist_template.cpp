#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

using namespace std;

struct node{

	int data;
	struct node *next;

};

template<class T>
class nodelist{

public:
	nodelist():head(NULL){}
	~nodelist(){}
	void insert(int data);
	T *deletenode(int data);
	void print(void);
	void reverse(void);
private:
	T *head;
};

template<class T>
void nodelist<T>::insert(int data)
{
	T *newnode = new T;
	newnode->data = data;
	newnode->next = NULL;

	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode->next = head;
		head = newnode;
	}
}

template<class T>
void nodelist<T>::print(void)
{
	T *curr = head;

	while(curr != NULL)
	{
		cout << curr->data << endl;
		curr = curr->next;
	}
}

template<class T>
T *nodelist<T>::deletenode(int data)
{
	T *curr = head;
	T *prev = NULL;
	bool flag = false;

	while(curr != NULL)
	{
		if(curr->data == data)
		{
			if(prev != NULL)
				prev->next = curr->next;
			else
				head = head->next;

			flag = true;

		}
		curr = curr->next;
	}

	if(flag)
		return curr;
	else
		return NULL;
}


template<class T>
void nodelist<T>::reverse(void)
{
	T *curr = head;
	T *nxt = NULL;
	T *prev = NULL;

	while(curr != NULL)
	{
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}

	head = prev;
}

int main(void)
{	
	nodelist<node> llist;

	llist.insert(1);
	llist.insert(2);
	llist.insert(3);
	llist.reverse();
	llist.print();
	
	return 0;
}





