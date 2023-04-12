#include <iostream>
#include <cassert>

class Node
{
public:
	int data;
	Node* next;

	Node(int data);
};

class List
{
private:
	/*class Node
	{
	public:
		int data;
		Node* next;

		Node(int data);
	};*/

	Node* first;
	int size;
public:
	List();
        
        List(List &ll);

        ~List();	
	
	int get_size();

	bool is_empty();

	void push_back(int data);
	
	void insert(int position, int data);
	
	int pop_back();
	
	int remove_by_index(int position);
	
	void remove_by_value(int data, int flag = 0);

	void print();
	
	int& operator[](int position);
};
