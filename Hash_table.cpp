#include <iostream>
#include <list>

using namespace std;

class hashmap {

	int buckets;
	list<int> *table;

public:
	hashmap(int size):buckets(size)
	{
		table = new list<int>[buckets];
	}

	~hashmap()
	{
		for (int i = 0; i < buckets; ++i)
		{
			list<int>::iterator itr = table[i].begin();
			while(itr != table[i].end())
			{
				table[i].erase(itr);
				itr++;
			}
		}
		delete [] table;
	}

	int hashindex(int key)
	{
		return(key % buckets);
	}

	void hashinsert(int key, int value)
	{
		int idx = hashindex(key);

		table[idx].push_back(value);
	}

	void displayhstable(void)
	{
		for (int i = 0; i < buckets; ++i)
		{
			cout << i;
			list<int>::iterator itr = table[i].begin();	
			// if(itr != table[i].end())
			// 	cout << i;
			while(itr != table[i].end())
			{
				cout << "-->" << *itr;
				itr++;
			}
			cout << endl;
		}
	}

	void hashdelete(int key)
	{
		int idx = hashindex(key);

		list<int>:: iterator itr = table[idx].begin();

		while(itr != table[idx].end())
		{
			table[idx].erase(itr);
			itr++;
		}
	}
};


int main()
{
	hashmap h1(20);

	h1.hashinsert(13, 33);
	h1.hashinsert(17, 5);
	h1.hashinsert(12, 7);
	h1.hashinsert(19, 90);

	h1.hashdelete(19);

	h1.displayhstable();
	return 0;
}
