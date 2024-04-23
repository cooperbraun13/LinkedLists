#include "linked_list.hpp"
#include <iostream>

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
		for (int counter = 0;counter < index-1;counter++){
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


