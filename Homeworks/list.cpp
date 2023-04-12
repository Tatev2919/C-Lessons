#include "list.hpp"

Node::Node(int data)
{
	this->data = data;
	next = nullptr;
}

List::List()
{
	first = nullptr;
	size = 0;
}

List::List(List &ll)
{
        std::cout << "Copy ctor" << std::endl;
 //	assert(this!=ll && ll.size >0 && "Wrong");

        Node* h = ll.first;
        for (int i = 0; i < ll.size ; ++i) {
                std::cout<< h->data << " " <<std::endl;
                push_back(h->data);
                h = h ->next;
        }
}

List::~List() 
{
	//assert(size > 0 && "Out of range. Incorrect index.");
        std::cout<< "Destrcutor called for list" << std::endl;
        Node* current = first;
        Node* next_n = nullptr;

        while (current != nullptr) {
            next_n = current-> next;
            delete current;
            current = next_n;
        }
       
}
	
int List::get_size()
{
	/*int size = 0;
	Node* n = first;
	while (n != nullptr)
	{
		size++;
		n = n->next;
	}*/
	return size;
}

bool List::is_empty()
{
	if (first == nullptr)
	{
		return true;
	}
	return false;
}

void List::push_back(int data)
{
        std::cout<< data << " is data " << std::endl;
	if (first == nullptr)
	{
		first = new Node(data);
	}
	else
	{
		Node* element = new Node(data);
		Node* n = first;
		while (n->next != nullptr)
		{
			n = n->next;
		}
		n->next = element;
	}
	size++;
        print();
}

void List::insert(int position, int data)
{
	assert(position >= 0 && position <= size && "Out of range. Incorrect index.");
	Node* element = new Node(data);
	if (position == 0)
	{
		element->next = first;
		first = element;
	}
	else
	{
		Node* n = first;
		for (int i = 0; i < position - 1; i++)
		{
			n = n->next;
		}
		element->next = n->next;
		n->next = element;
	}
	size++;
}

int List::pop_back()
{
	assert(size > 0 && "The list is empty. No element to remove");
	if (size > 1)
	{
		Node* n = first;
		Node* n_prev;
		while (n->next != nullptr)
		{
			n_prev = n;
			n = n->next;
		}
		int d = n->data;
		delete n;
		n_prev->next = nullptr;
		size--;
		return d;
	}
	else if (size == 1)
	{
		delete first;
		first = nullptr;
		size--;
	}
	return 0;
}

int List::remove_by_index(int position)
{
	assert(size > 0 && "The list is empty. No element to remove.");
	assert(position >= 0 && position < size && "Out of range. Incorrect index.");
	int d = first->data;
	if (size == 1)
	{
		delete first;
		first = nullptr;
	}
	else if (position == 0)
	{
		Node* n = first->next;
		delete first;
		first = n;
	}
	else
	{
		Node* n = first;
		Node* n_prev;
		for(int i = 0; i < position; i++)
		{
			n_prev = n;
			n = n->next;
		}
		d = n->data;
		n_prev->next = n->next;
		delete n;
	}
	size--;
	return d;
}

void List::remove_by_value(int data, int flag)
{
	assert(size > 0 && "The list is empty. No element to remove.");
	assert(flag == 0 || flag == 1 && "Incorrect flag");
	
	int s = size;
	Node* n = first->next;	
	if (flag == 0)
	{
		if (first->data == data)
		{
			delete first;
			first = n;
			size--;
			return;
		}

		else
		{
			Node* n_prev = first; 
			for (int i = 1; i < size; i++)
			{
				if (n->data == data)
				{
					n_prev->next = n->next;
					delete n;
					size--;
					return;
				}
				else
				{
					n_prev = n;
				       	n = n->next;
				}
			}
		}
	}

	else if (flag == 1)
	{
		while (size > 0 && first->data == data)
		{
			delete first;
			first = n;
			size--;
			if (first != nullptr)
			{
				n = first->next;
			}
		}

		if (size > 1)
		{
			Node* n_prev = first;
			for (int i = 1; i < size; i++)
			{
				if (n->data == data)
				{
					n_prev->next = n->next;
					delete n;
					size--;
					n_prev = n;
					n = n->next;
				}
			}
		}
	}
	if (s == size)
	{
		std::cout << "Element with value " << data << " does not exist in the list" << std::endl;
	}
}

void List::print()
{
	Node* n = first;
	while (n != nullptr)
	{
		std::cout << n->data << " ";
		n = n->next;
	}
	std::cout << std::endl;
}

int& List::operator[](int position)
{
	assert(position >= 0 && position < size && "Out of range. Incorrect index.");
	Node* n = first;
	for (int i = 0; i < position; i++)
	{
		n = n->next;
	}
	return n->data;
}

