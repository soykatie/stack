#include "Stack.h"

const int MAX_INT_SIZE = 11;

Stack::Stack()
{
	this->head = nullptr;
}

Stack::Stack(int value)
{
	Node* helper = new Node(value);
	this->head = helper;
}

Stack::Stack(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		this->push(array[i]);
	}
}

Stack::Stack(const Stack& stack)
{
	if (stack.head) 
	{
		Node* currentStack = stack.head;
		head = new Node(stack.head->value);
		while (currentStack = currentStack->next) 
		{
			push(currentStack->value);
		}
	}
	else 
	{
		head = stack.head;
	}
}

Stack::~Stack() { deleteAll(); }

void Stack::deleteAll() 
{
	while (head)
	{
		if (head != nullptr)
		{
			Node* tmp;
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}
}

void Stack::push(int value)
{
	if (head == nullptr)
	{
		addAfter(head, value);
	}
	else {

		Node* current = head;
		Node* previous = head;
		while (current) {
			previous = current;
			current = current->next;
		}
		addAfter(previous, value);
	}
}

void Stack::pop()
{
	if (head == nullptr)
	{
		return;
	}

	if (head->next == nullptr)
	{
		if (head != nullptr)
		{
			Node* tmp;
			tmp = head;
			head = head->next;
			delete tmp;
		}
		return;
	}
	else
	{
		Node* curr = head;
		while (curr->next->next)
		{
			curr = curr->next;
		}
		delete curr->next;
		curr->next = nullptr;
	}
}

void Stack::addAfter(Node*& node, int value)
{
	Node* temp = new Node(value);
	if (node != nullptr)
	{
		temp->next = node->next;
		node->next = temp;
	}
	else node = temp;
}

void Stack::displayStack(Stack& stack)
{
	while (!stack.isEmpty())
	{
		cout << stack.top() << endl;
		stack.pop();
	}
}

bool Stack::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	else
		return false;
}

int Stack::getSize() const
{
	int size = 0;
	if (head != nullptr)
	{
		Node* current = head;
		while (current)
		{
			size++;
			current = current->next;
		}
	}
	return size;
}

int Stack::top()
{
	if (head != nullptr)
	{
		return head->value;
	}
}

ostream& operator<<(ostream& stream, const Stack stack)
{
	Node* current = stack.head;

	if (!current)
	{
		stream << "The stack is empty!" << endl;
	}
	while (current)
	{
		stream << current->value << " ";
		current = current->next;
	}
	return stream;
}

Stack Stack::mergeStack(Stack stack1, Stack stack2)
{
	Stack stack3;
	if (stack1.head != nullptr && stack2.head != nullptr) 
	{
		Node* current1 = stack1.head;
		Node* current2 = stack2.head;

		int detector1 = 1;
		int detector2 = 1;

		while (detector1 || detector2)
		{
			if (current1->value < current2->value) 
			{
				stack3.push(current1->value);
				if (current1->next) 
				{
					current1 = current1->next;
				}
				else 
				{
					detector1 = 0;
				}
			}
			else 
			{
				stack3.push(current2->value);
				if (current2->next) 
				{
					current2 = current2->next;
				}
				else 
				{
					detector2 = 0;
				}
			}

			if (current1->next == nullptr && current2->next == nullptr) 
			{
				if (current1->value > current2->value) 
				{
					stack3.push(current2->value);
					stack3.push(current1->value);
				}
				else 
				{
					stack3.push(current1->value);
					stack3.push(current2->value);
				}
				detector1 = detector2 = 0;
			}

			if (detector1 == 0 && detector2 != 0) 
			{
				while (current2->next)
				{
					if (current2->value < current2->next->value) 
					{
						stack3.push(current2->value);
					}
					else 
					{
						stack3.push(current2->value);
					}
					current2 = current2->next;
				}
				stack3.push(current2->value);
				detector2 = 0;
			}

			if (detector2 == 0 && detector1 != 0) 
			{
				while (current1->next)
				{
					if (current1->value < current1->next->value) 
					{
						stack3.push(current1->value);
					}
					else 
					{
						stack3.push(current1->value);
					}
					current1 = current1->next;
				}
				stack3.push(current1->value);
				detector1 = 0;
			}
		}
	}
	return stack3;
}

Stack Stack::operator=(const Stack& ob)
{
	if (&ob == this) return *this;
	deleteAll();
	redefineStack(ob);
	return Stack(ob);
}

void Stack::redefineStack(const Stack ob)
{
	if (ob.head) 
	{
		deleteAll();
		Node* current = ob.head;
		this->head = new Node(ob.head->value);
		while (current = current->next) 
		{
			push(current->value);
		}
	}
	else {
		this->head = ob.head;
	}
}

void Stack::redefineStack(int* arr, int size)
{
	deleteAll();
	head = nullptr;
	for (int i = 0; i < size; i++) 
	{
		push(arr[i]);
	}
}

char* Stack::toString() const
{
	char* outString;
	char buffer[MAX_INT_SIZE] = "";
	int size = MAX_INT_SIZE * getSize() + 3;//3 - это {} и \0
	outString = new char[size];
	strcpy_s(outString, size, "{");
	if (head != nullptr)
	{
		Node* current = head;
		while (current) 
		{
			_itoa_s(current->value, buffer, 10);
			strcat_s(outString, size, buffer);
			if (current->next != nullptr)
			{
				strcat_s(outString, size, ", ");
			}
			current = current->next;
		}
	}
	strcat_s(outString, size, "}");
	return outString;
}
