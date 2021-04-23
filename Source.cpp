#include <iostream>
template <typename T>
class list
{
private:
	template <typename T>
	class Node
	{
	public:
		Node* next;
		T data;
		Node(T data = T(), Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	Node<T>* head;
	size_t size;
public:
	list() : head(nullptr), size(0) {}
	void add_last(T data);
	void add_first(T data);
	void del_first();
	void del_last();
	void del_last_param(Node<T>* next);
	void print();
	T& operator[](int index);
	Node<T>* get_head()
	{
		return this->head;
	}
	size_t get_size()
	{
		return this->size;
	}
};

template<typename T>
void list<T>::add_last(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* tmp = head;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node<T>(data);
	}
	size++;
}
template<typename T>
void list<T>::add_first(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* tmp = new Node<T>(data);
		tmp->next = head;
		head = tmp;
	}
	size++;
}
template<typename T>
void list<T>::del_first()
{
	Node<T>* tmp = head;
	head = head->next;
	delete tmp;
	size--;
}
template<typename T>
void list<T>::del_last_param(Node<T>* current)
{
	if (current!= nullptr && current->next != nullptr)
	{
		Node<T>* tmp = current->next;
		Node<T>* nl = current;
		if (tmp->next == nullptr)
		{
			delete tmp;
			nl->next = nullptr;
			size--;
			return;
		}
		del_last_param(current->next);
	}
	else
	{
		head=nullptr;//delete head
	}
	size--;
}

template<typename T>
void list<T>::del_last()
{
	if (head != nullptr && head->next != nullptr)
	{
		Node<T>* tmp = head->next;
		Node<T>* nl = head;
		while (tmp->next)
		{
			tmp = tmp->next;
			nl = nl->next;
		}
		delete tmp;
		nl->next = nullptr;
	}
	else
	{
		delete head;
	}
	size--;
}

template<typename T>
T& list<T>::operator[](int index)
{
	Node<T>* tmp = head;
	int counter = 0;
	while (tmp)
	{
		if (counter == index) return tmp->data;
		tmp = tmp->next;
		counter++;
	}
}

int main()
{
	list<int> A;
	A.add_last(4);
	//A.add_last(86);
	//A.add_last(99);
	for (size_t i = 0; i < A.get_size(); i++)
	{
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
	A.del_last_param(A.get_head());
	for (size_t i = 0; i < A.get_size(); i++)
	{
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
	//A.add_last(12);
	A.add_last(99);
	for (size_t i = 0; i < A.get_size(); i++)
	{
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
	A.add_first(1);
	for (size_t i = 0; i < A.get_size(); i++)
	{
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
	A.add_first(22);
	for (size_t i = 0; i < A.get_size(); i++)
	{
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
	//A.del_last_param(A.get_head());
	for (size_t i = 0; i < A.get_size(); i++)
	{
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
	A.add_last(8);
	for (size_t i = 0; i < A.get_size(); i++)
	{
		std::cout << A[i] << " ";
	}
	//A.del_last_param(A.get_head());
	std::cout << std::endl;
	A.del_first();
		for (size_t i = 0; i < A.get_size(); i++)
		{
			std::cout << A[i] << " ";
		}
}
