#include <iostream>

void forward_linked_list();
void double_linked_list();

int main()
{
	//forward_linked_list();
	double_linked_list();
	
	return 0;
}


void forward_linked_list()
{
	typedef struct node
	{
		int data = 0;
		node *next = NULL; // Pointer to next node
	};

	int num = 1; // user input

	// First node
	node *root = new node;

	// Current node
	node *current = new node;
	current = root;

	while (num != 0)
	{
		// Receive input
		std::cout << "Enter numbers to populate linked list. Enter 0 to quit" << std::endl;
		std::cin >> num;

		if (num != 0)
		{
			node *newNode = new node;

			current->next = newNode;
			current->data = num;
			current = current->next;
		}
		else
		{
			break;
		}
	}

	current = root;
	while (current->next != NULL)
	{
		std::cout << current->data << std::endl;
		current = current->next;
	}

	int dummy = 0;
	std::cin >> dummy;
}

void double_linked_list()
{
	typedef struct node
	{
		int data = 0;
		node *prev = NULL;
		node *next = NULL;
	};

	int num = 0;
	int node_index = 0;

	// Construct first and current nodes
	node *root = new node;
	node *current = new node;

	// Set current node to the first node
	current = root;

	// Get input
	do
	{
		std::cout << "Enter numbers to populate linked list. Enter 0 to quit." << std::endl;
		std::cout << "node data: ";
		std::cin >> num;

		// Do not log num into the linked list if it's 0
		if (num != 0)
		{
			// Construct a new node each time
			node *newNode = new node;

			// Set current data to input
			current->data = num;

			// Set current pointers to previous and next nodes
			newNode->prev = current;
			current->next = newNode;

			// Set current to be next node
			current = current->next;

			std::cout << "index: " << node_index++ << std::endl;
		}

	} while (num != 0);

	node_index = 0;
	
	// Set current to be first node to start listing
	current = root;

	std::cout << "--------------- Forwards --------------" << std::endl;

	// Iterate forwards
	while (current->next != NULL)
	{
		std::cout << "node data: " << current->data << std::endl;
		std::cout << "index: " << node_index++ << std::endl;

		current = current->next;
	}

	std::cout << "--------------- Backwards -------------" << std::endl;

	node_index = 0;

	// Iterate backwards
	while (current->prev != NULL)
	{
		current = current->prev;

		std::cout << "node data: " << current->data << std::endl;
		std::cout << "index: " << node_index++ << std::endl;
	}

	std::cout << "---------------------------------------" << std::endl;

	// Don't let program quit
	int dummy = 0;
	std::cin >> dummy;

}