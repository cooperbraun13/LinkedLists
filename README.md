# LinkedLists
Provides a comprehensive implementation of a singly linked list, complete with functionalities for node manipulation and list operations.

The Node class represents the elements (nodes) in the linked list. Each node contains:

int value: the integer value stored in the node.
Node* next: a pointer to the next node in the list.

Constructors:

Node(): Initializes a node with default values.
Node(int value): Initializes a node with the specified value.
Node(int value, Node* next_ptr): Initializes a node with the specified value and next pointer.
Node(Node* nde): Initializes a node as a copy of another node.

Destructor:

~Node(): Cleans up the node, primarily ensuring no memory leaks if dynamic memory allocation was used.
LinkedList Class
The LinkedList class provides a structure for managing a collection of nodes. It supports various operations for manipulating linked lists.

Constructors:

LinkedList(): Initializes an empty linked list.
LinkedList(int value): Initializes a linked list with a single node containing the specified value.
LinkedList(Node* start): Initializes a linked list starting from the specified node.
LinkedList(LinkedList* lst): Initializes a linked list as a copy of another list.
LinkedList(int* arr, int size): Initializes a linked list from an array of integers.
LinkedList(std::vector<int> vec): Initializes a linked list from a vector of integers.

Member Functions:

Node* get_head() const: Returns the head node of the list.
int size() const: Returns the number of nodes in the list.
bool is_empty() const: Checks if the list is empty.
bool push_back(int value): Appends a node with the specified value to the end of the list.
bool push_front(int value): Prepends a node with the specified value to the front of the list.
bool insert(int index, int value): Inserts a node with the specified value at the given index.
bool remove(int index): Removes the node at the specified index.
bool remove_value(int value): Removes the first node containing the specified value.
int search(int value) const: Returns the index of the first node containing the specified value.
void print() const: Prints the contents of the list.

Destructor:

~LinkedList(): Destroys the linked list, releasing all associated resources.

This linked list implementation can be utilized in applications where data is dynamically added and removed. It offers flexibility with direct manipulation of nodes and allows for the handling of data in a linear structure.
