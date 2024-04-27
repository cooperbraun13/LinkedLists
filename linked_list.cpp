#include "linked_list.hpp"
#include <iostream>
#include <vector>

Node::Node() {
	value = 0;
	next = nullptr;
}

Node::Node(int value) {
	this->value = value;
	next = nullptr;
}

Node::Node(int value, Node* next_ptr) {
	this->value = value;
	next = next_ptr;
}

// copy constructor
Node::Node(Node* nde) {
	value = nde->value;
	next = nde->next;
}

LinkedList::LinkedList() {
	head = nullptr;
}

LinkedList::LinkedList(int value) {
	head = new Node(value);
}

LinkedList::LinkedList(Node* start) {
	head = start;
}

// copy constructor
LinkedList::LinkedList(LinkedList* lst) {
	head = nullptr;
	Node* curr = lst->head;
	while (curr != nullptr) {
		push_back(curr->value);
		curr = curr->next;
	}
}

LinkedList::LinkedList(int* arr, int size) {
	head = nullptr;
	for (int counter = 0; counter < size; counter++) {
		push_back(arr[counter]);
	}
}

LinkedList::LinkedList(std::vector<int> vec) {
	head = nullptr;
	for (int value : vec) {
		push_back(value);
	}
}

Node::~Node() { 
    if (next != nullptr) {
        delete next;
        next = nullptr;
    }
}

LinkedList::~LinkedList() {
    if (head != nullptr) {
        delete head;
        head = nullptr;
    }
}

Node* LinkedList::get_head() const{
    return head;
}

bool LinkedList::push_back(int value) { 
    if (head == nullptr) {
	head = new Node;
	head->next = nullptr;
	head->value = value;
    }
    else {
	Node* iter;
	for (iter = head; iter->next != nullptr; iter = iter->next);
	iter->next = new Node;
	iter->next->next = nullptr;
	iter->next->value = value;
    }
    return true;
}

bool LinkedList::is_empty() const {
	return head == nullptr;
}

int LinkedList::size() const {
	if(is_empty()){
		return 0;
	}
	Node* iter = head;
	int counter = 1;
	while (iter->next != nullptr) {
		counter++;
		iter=iter->next;
	}
	return counter;
}

bool LinkedList::push_front(int value) { 
	Node* new_node = new Node;
	new_node->next = head;
	new_node->value = value;
	head = new_node;
	return true;
}

bool LinkedList::insert(int index, int value) {
	if (index <= size() && index >= 0) {
		if(index == 0) {
			return push_front(value);
		}
		Node* iter = head;
		for (int counter = 0; counter < index - 1; counter++){
			iter = iter->next;
		}
		Node* new_node = new Node;
		new_node->value = value;
		new_node->next = iter->next;
		iter->next = new_node;
		return true;
	}
	else {
		return false;
	}	
}

bool LinkedList::remove(int index) {
	if(index < 0 || index >= size() || size() == 0) {
		return false;
	}
	if (index == 0) {
		Node* temp = head;
		head = head->next;
		temp->next = nullptr;
		delete temp;
		return true;
	}
	Node* iter = head;
	int counter = 0;
	while (counter < index - 1) {
		iter = iter->next;
		counter++;
	}
	Node* temp = iter->next;
	iter->next = temp->next;
	temp->next = nullptr;
	delete temp;
	return true;
}

bool LinkedList::remove_value(int value) {
	if (is_empty()) {
		return false;
	}
	Node* temp = head;
	Node* prev = nullptr;

	while (temp != nullptr && temp->value != value) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == nullptr) {
		return false;
	}
	if (prev == nullptr) {
		head = temp->next;
	} else {
		prev->next = temp->next;
	}
	delete temp;
	return true;
}

int LinkedList::search(int value) const {
	if (is_empty()) {
		return -1;
	}
	Node* curr = head;
	int index = 0;

	while (curr != nullptr && curr->value != value) {
		curr = curr->next;
		index++;
	}
	if (curr != nullptr) {
		return index;
	} else {
		return -1;
	}
}

void LinkedList::print() const {
	if (is_empty()) {
		std::cout << "list is empty" << std::endl;
	} else {
		Node* curr = head;
		while (curr != nullptr) {
			std::cout << curr->value << " ";
			curr = curr->next;
		}
		std::cout << std::endl;
	}
}



